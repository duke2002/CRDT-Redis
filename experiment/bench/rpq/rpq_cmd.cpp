//
// Created by admin on 2020/1/8.
//

#include "rpq_cmd.h"

#define DEFINE_ACTION(_name) #_name,
const char *rpq_type_str[] = {RPQ_TYPE_CODEC(DEFINE_ACTION)};
#undef DEFINE_ACTION

void rpq_cmd::exec(redis_client &c)
{
    char name[128];
    sprintf(name, "%srpq", rpq_type_str[static_cast<int>(zt)]);
    char tmp[256];
    switch (t)
    {
        case rpq_op_type::add:
            sprintf(tmp, "%szadd %s %d %f", rpq_type_str[static_cast<int>(zt)], name, e, d);
            break;
        case rpq_op_type::incrby:
            sprintf(tmp, "%szincrby %s %d %f", rpq_type_str[static_cast<int>(zt)], name, e, d);
            break;
        case rpq_op_type::rem:
            sprintf(tmp, "%szrem %s %d", rpq_type_str[static_cast<int>(zt)], name, e);
            break;
        case rpq_op_type::max:
            sprintf(tmp, "%szmax %s", rpq_type_str[static_cast<int>(zt)], name);
            break;
        case rpq_op_type::overhead:
            sprintf(tmp, "%szoverhead %s", rpq_type_str[static_cast<int>(zt)], name);
            break;
        case rpq_op_type::opcount:
            sprintf(tmp, "%szopcount", rpq_type_str[static_cast<int>(zt)]);
            break;
    }
    auto r = c.exec(tmp);
    switch (t)
    {
        case rpq_op_type::add:
            ele.add(e, d);
            break;
        case rpq_op_type::incrby:
            ele.inc(e, d);
            break;
        case rpq_op_type::rem:
            ele.rem(e);
            break;
        case rpq_op_type::max:
        {
            int k = -1;
            double v = -1;
            if (r->elements == 2)
            {
                k = atoi(r->element[0]->str); // NOLINT
                v = atof(r->element[1]->str); // NOLINT
            }
            ele.max(k, v);
            break;
        }
        case rpq_op_type::overhead:
            ele.overhead(static_cast<int>(r->integer));
            break;
        case rpq_op_type::opcount:
            printf("%lli\n", r->integer);
            break;
    }
}
