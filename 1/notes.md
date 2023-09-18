
Header File: <linux/rwlock_types.h>

Data Structure: struct rwlock_t

Initialization:
================

	static: DEFINE_RWLOCK(x)

	Dynamic: rwlock_init(lock);


Lock/Unlock:
================

	Readers:

		read_lock(&mr_rwlock);
		/* critical section (read only) ... */
		read_unlock(&mr_rwlock);

	Writers:

		write_lock(&mr_rwlock);
		/* critical section (read and write) ... */
		write_unlock(&mr_lock);
