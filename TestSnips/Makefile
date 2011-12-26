NEED_PTHREAD_APP=test_cocurrent_add test_exception_in_thread
BUILD = test_epoll test_statfs test_fopen perror test_vtable_layout test_malloc test_cframe \
       test_memcpy test_strcmp\
       test_boost_shared_ptr \
       test_loop \
       test_string \
       test_sizeof_cstr \
       test_vector \
       test_gettimeofday \
       test_mem_layout \
       test_ace \
       test_union \
       test_spirit \
       test_delete_const_pointer \
       endian \
       test_memleak \
       memory_usage_of_set_implments \
       zmq \
       $(NEED_PTHREAD_APP)

all:$(BUILD)

CFLAGS=-g -O0
CXXFLAGS=-g -O0
test_cocurrent_add : test_cocurrent_add.c
	$(CC) -o $@ $< -lpthread

test_exception_in_thread: test_exception_in_thread.cpp
	$(CXX) -o $@ $< -lpthread

test_boost_shared_ptr: test_boost_shared_ptr.cpp
	$(CXX) -o $@ $< -lpthread

test_ace: test_ace.cpp
	$(CXX) -o $@ $< -lACE -D_FILE_OFFSET_BITS=64

zmq: zmq.c
	$(CC) -o $@ $< -lczmq -lzmq
clean:
	rm -f $(BUILD)
