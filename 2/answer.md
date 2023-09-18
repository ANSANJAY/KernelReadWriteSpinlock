What happens when we run the below code snippet?

read_lock(&mylock);
write_lock(&mylock);


Executing these two functions will cause deadlock, as write_lock will spin until it all readers have released the lock.
