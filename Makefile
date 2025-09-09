  # the compiler: gcc for C program, define as g++ for C++
  CC = gcc

  # compiler flags:
  #  -g    adds debugging information to the executable file
  #  -Wall turns on most, but not all, compiler warnings
  CFLAGS  = -g -Wall

  # the build target executable:
  #TARGET = linked_list_practice/int_link
  #TARGET = linked_list_practice/array_link
  #TARGET = linked_list_practice/insert
  #TARGET = linked_list_practice/delete
  #TARGET = linked_list_practice/circular_linkedlist
  #TARGET = linked_list_practice/segregate_even_odd
  #TARGET = linked_list_practice/merge_sort_linkedlist
  #TARGET = linked_list_practice/Xor_linked_list
  #TARGET = linked_list_practice/linked_list_lenght
  #TARGET = linked_list_practice/search_linked_list
  #TARGET = linked_list_practice/get_node_index
	#TARGET  = detect_loop_in_lnk
  #TARGET  =  linked_list_practice/reverse_list
	#TARGET  =  linked_list_practice/swap_nodes_in_linkedlist
	#TARGET  =  linked_list_practice/remove_duplicates_sorted_LL
	#TARGET  =  linked_list_practice/remove_duplicates_unsorted_LL
	#TARGET  =  linked_list_practice/skipMdeleteNnodes
	#TARGET  =  linked_list_practice/intersection_point_of_LL
	#TARGET  =  linked_list_practice/lenght_of_loop_in_LL
	#TARGET  =  linked_list_practice/find_nth_node_from_end_of_LL
	#TARGET  =  linked_list_practice/find_nth_node_from_end_of_LL_2
	#TARGET  =  linked_list_practice/sorted_merge_two_LL
	#TARGET  =  linked_list_practice/deleate_current_node_in_LL
	#TARGET  =  linked_list_practice/clone_linked_list


	#TARGET = queues_practice/Queue_1
  #TARGET = queues_practice/queue_using_ll
  #TARGET = queues_practice/priority_queue
	#TARGET  = queues_practice/reverse_queue

  #TARGET = stack_practice/reverse_string
	#TARGET = stack_practice/queue_using_stacks
  #TARGET = stack_practice/stack_1
  #TARGET = stack_practice/array_stack
  #TARGET = stack_practice/stack_lnklst
	#TARGET = stack_practice/balancing_of_symbols

  #TARGET = hash_table/seperate_chaining
  #TARGET = hash_table/Linear_probing_Open_Addressing
  #TARGET = hash_table/double_hashing_technique
  #TARGET = hash_table/hash_c
  #TARGET = hash_table/trivial_hashing
  #TARGET = hash_table/hash_lookups
  #TARGET = hash_table/first_repeated_char_hash
  #TARGET = hash_table/hash_chain_collision_resolution


  #TARGET = sorting_practice/selection_sort
	#TARGET = sorting_practice/bubble_sort
	#TARGET = sorting_practice/insertion_sort
	#TARGET = sorting_practice/merge_sort
	#TARGET = sorting_practice/quick_sort
	#TARGET  = sorting_practice/quick_sort_iterative
	#TARGET  = sorting_practice/merge_sort_iterative
	#TARGET = searching_practice/linear_search
	#TARGET = searching_practice/binary_search
  #TARGET = array_qna/search_in_rotated_array

  #TARGET = tree/binary_tree/new_tree
  #TARGET = misc/sliding_window
	#TARGET = misc/vector

  #TARGET = graph/bipartite_graph_check
  #TARGET = graph/bipartite_nonconnected_graphs
	#TARGET = graph/bipartite_matching
	#TARGET = graph/directed_graph

	#TARGET = Matrix/matrix_addition
	#TARGET = Matrix/matrix_subtraction
	#TARGET = Matrix/scalar_multiplication
	#TARGET = Matrix/matrix_transpose
	#TARGET = Matrix/matrix_multiplication
	#TARGET = Matrix/matrix_elimination
	#TARGET = Matrix/sparse_representation
	#TARGET = Matrix/gauss_elimination
	#TARGET = Matrix/LU_decomposition

	TARGET = ds_application/LRU_Cache

  all: $(TARGET).c
	$(CC) $(CFLAGS) -o exe $(TARGET).c

  clean:
	$(RM) exe
