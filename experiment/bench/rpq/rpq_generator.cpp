//
// Created by admin on 2020/1/8.
//

#include "rpq_generator.h"

#define PA (pattern->PR_ADD)
#define PI (pattern->PR_ADD + pattern->PR_INC)
#define PAA (pattern->PR_ADD_CA)
#define PAR (pattern->PR_ADD_CA + pattern->PR_ADD_CR)
#define PRA (pattern->PR_REM_CA)
#define PRR (pattern->PR_REM_CA + pattern->PR_REM_CR)

op_gen_pattern pt_dft{
    .PR_ADD = 0.41,
    .PR_INC = 0.2,
    .PR_REM = 0.39,

    .PR_ADD_CA = 0.15,
    .PR_ADD_CR = 0.05,
    .PR_REM_CA = 0.1,
    .PR_REM_CR = 0.1};

op_gen_pattern pt_ard{
    .PR_ADD = 0.11,
    .PR_INC = 0.8,
    .PR_REM = 0.09,

    .PR_ADD_CA = 0.15,
    .PR_ADD_CR = 0.05,
    .PR_REM_CA = 0.1,
    .PR_REM_CR = 0.1};

void rpq_generator::gen_and_exec(redis_client &c)
{
    rpq_op_type t;
    int e;
    double d;
    double rand = decide();
    if (rand <= PA)
    {
        t = rpq_op_type::add;
        d = gen_initial();
        double conf = decide();
        if (conf < PAA)
        {
            e = add.get(-1);
            if (e == -1)
            {
                e = gen_element();
                add.add(e);
            }
        }
        else if (conf < PAR)
        {
            e = rem.get(-1);
            if (e == -1)
                e = gen_element();
            add.add(e);
        }
        else
        {
            e = gen_element();
            add.add(e);
        }
    }
    else if (rand <= PI)
    {
        t = rpq_op_type::incrby;
        e = ele.random_get();
        if (e == -1)return;
        d = gen_increament();
    }
    else
    {
        t = rpq_op_type::rem;
        d = -1;
        double conf = decide();
        if (conf < PRA)
        {
            e = add.get(-1);
            if (e == -1)
            {
                e = ele.random_get();
                if (e == -1)return;
            }
            rem.add(e);
        }
        else if (conf < PRR)
        {
            e = rem.get(-1);
            if (e == -1)
            {
                e = ele.random_get();
                if (e == -1)return;
                rem.add(e);
            }
        }
        else
        {
            e = ele.random_get();
            if (e == -1)return;
            rem.add(e);
        }
    }
    rpq_cmd(zt, t, e, d, ele).exec(c);
}

