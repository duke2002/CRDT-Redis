cmake_minimum_required(VERSION 3.9)
project(redis_6_0_5)

set(CMAKE_C_STANDARD 11)

include_directories(deps/hiredis deps/linenoise deps/lua/src)

add_executable(redis_6_0_5
        src/modules/helloacl.c
        src/modules/helloblock.c
        src/modules/hellocluster.c
        src/modules/hellodict.c
        src/modules/hellohook.c
        src/modules/hellotimer.c
        src/modules/hellotype.c
        src/modules/helloworld.c
        src/modules/testmodule.c
        src/acl.c
        src/adlist.c
        src/adlist.h
        src/ae.c
        src/ae.h
        src/ae_epoll.c
        src/ae_evport.c
        src/ae_kqueue.c
        src/ae_select.c
        src/anet.c
        src/anet.h
        src/aof.c
        src/asciilogo.h
        src/atomicvar.h
        src/bio.c
        src/bio.h
        src/bitops.c
        src/blocked.c
        src/childinfo.c
        src/cluster.c
        src/cluster.h
        src/config.c
        src/config.h
        src/connection.c
        src/connection.h
        src/connhelpers.h
        src/crc16.c
        src/crc16_slottable.h
        src/crc64.c
        src/crc64.h
        src/crcspeed.c
        src/crcspeed.h
        src/db.c
        src/debug.c
        src/debugmacro.h
        src/defrag.c
        src/dict.c
        src/dict.h
        src/endianconv.c
        src/endianconv.h
        src/evict.c
        src/expire.c
        src/fmacros.h
        src/geo.c
        src/geo.h
        src/geohash.c
        src/geohash.h
        src/geohash_helper.c
        src/geohash_helper.h
        src/gopher.c
        src/help.h
        src/hyperloglog.c
        src/intset.c
        src/intset.h
        src/latency.c
        src/latency.h
        src/lazyfree.c
        src/listpack.c
        src/listpack.h
        src/listpack_malloc.h
        src/localtime.c
        src/lolwut.c
        src/lolwut.h
        src/lolwut5.c
        src/lolwut6.c
        src/lzf.h
        src/lzf_c.c
        src/lzf_d.c
        src/lzfP.h
        src/memtest.c
        src/module.c
        src/multi.c
        src/networking.c
        src/notify.c
        src/object.c
        src/pqsort.c
        src/pqsort.h
        src/pubsub.c
        src/quicklist.c
        src/quicklist.h
        src/rand.c
        src/rand.h
        src/rax.c
        src/rax.h
        src/rax_malloc.h
        src/rdb.c
        src/rdb.h
        src/redis-benchmark.c
        src/redis-check-aof.c
        src/redis-check-rdb.c
        src/redis-cli.c
        src/redisassert.h
        src/redismodule.h
        src/release.c
        src/replication.c
        src/rio.c
        src/rio.h
        src/scripting.c
        src/sds.c
        src/sds.h
        src/sdsalloc.h
        src/sentinel.c
        src/server.c
        src/server.h
        src/setcpuaffinity.c
        src/setproctitle.c
        src/sha1.c
        src/sha1.h
        src/sha256.c
        src/sha256.h
        src/siphash.c
        src/slowlog.c
        src/slowlog.h
        src/solarisfixes.h
        src/sort.c
        src/sparkline.c
        src/sparkline.h
        src/stream.h
        src/syncio.c
        src/t_hash.c
        src/t_list.c
        src/t_set.c
        src/t_stream.c
        src/t_string.c
        src/t_zset.c
        src/testhelp.h
        src/timeout.c
        src/tls.c
        src/tracking.c
        src/util.c
        src/util.h
        src/version.h
        src/ziplist.c
        src/ziplist.h
        src/zipmap.c
        src/zipmap.h
        src/zmalloc.c
        src/zmalloc.h
        src/p2p.c src/vector_clock.h src/vector_clock.c src/t_ozset.c src/t_rwfzset.c src/RWFramework.h src/RWFramework.c src/CRDT.h src/lamport_clock.h src/t_rwflist.c src/t_rzset.c src/t_rlist.c src/list_basics.h src/list_basics.c src/CRDT_exp.h)
