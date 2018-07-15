cmake_minimum_required(VERSION 3.10)
project(Master_2_7 C)

set(CMAKE_C_STANDARD 11)

add_executable(Master_2_7 main.c CDA_module/cda.c CDA_module/cda_p.h CDA_module/cda.h
        CDA_module/Doubly_LInked_List/doubly_linked_list.h CDA_module/Doubly_LInked_List/doubly_linked_list_p.h
        CDA_module/Doubly_LInked_List/doubly_linked_list.c CDA_module/Doubly_LInked_List/TIPS_module/tips_p.h
        CDA_module/Doubly_LInked_List/TIPS_module/tips.h CDA_module/Doubly_LInked_List/TIPS_module/tips.c
        CDA_module/CPX/cpx.c CDA_module/CPX/cpx.h CDA_module/CPX/cpx_p.h CDA_module/LIST/list.c
        CDA_module/LIST/list.h CDA_module/LIST/list_p.h CDA_module/ALIST/list.c CDA_module/ALIST/list.h
        CDA_module/ALIST/list_p.h CDA_module/ELIST/list.c CDA_module/ELIST/list.h CDA_module/ELIST/list_p.h
        CDA_module/QUEUE/queue.c CDA_module/QUEUE/queue.h CDA_module/QUEUE/queue_p.h CDA_module/QUEUE/queue_usage.c CDA_module/BTREE/btree.c CDA_module/BTREE/btree.h CDA_module/BTREE/btree_p.h)