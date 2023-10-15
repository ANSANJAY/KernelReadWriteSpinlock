### 1. Explain the Technical Concept 📘

- **Reader-Writer Locks**: 
  - When a **read lock** is held, additional readers can also acquire the lock, but writers are blocked.
  - When a **write lock** is held, both readers and writers are blocked until the lock is released.
  - However, when a writer is waiting and a new reader arrives, the actual behavior can depend on the specific reader-writer lock implementation and its policy (writer-preference, reader-preference, or fair).
 
- **In the Linux Kernel**:
  - The kernel's `rwlock` typically follows a writer-preference policy.
  - When a writer is waiting for an `rwlock`, subsequent readers get blocked even if the lock is currently held by another reader.
  - This is to prevent writer starvation. Otherwise, in a high read-concurrency situation, writers might never get the lock.

### 2. Curious Questions 🧐💬

- **Question 1**: What does "writer-preference" in reader-writer lock policy mean and why might it be chosen?
  - **Answer**: Writer-preference means that if a writer is waiting for a lock, subsequent read-lock requests will wait even if the lock could be acquired for reading, in order to prioritize the writer. It's chosen to prevent writer starvation because writers, requiring exclusive access, can be blocked for an extended period in high read-concurrency situations.
  
- **Question 2**: How does the writer-preference policy impact system performance and fairness?
  - **Answer**: Writer-preference can potentially lead to reader starvation if writers continuously seek the lock. However, it ensures that write operations, which might be critical, are not unduly delayed, maintaining data timeliness and consistency across reading threads.

- **Question 3**: Can the starvation problem be completely solved with the current locking mechanisms available in the Linux kernel?
  - **Answer**: It's challenging to entirely eliminate starvation using conventional locking mechanisms. Fine-tuning a locking strategy might require considering specific use-cases, workload characteristics, and incorporating additional synchronization or scheduling techniques to ensure fair access to resources for all threads.

### 3. Simple Words Explanation 🍦🗣️

- **Imagine**: A popular library 📚 has a rule – if someone intends to write 📝 notes in a book, everyone must wait. Reading 📖, however, is usually open to all.

- **Scenario**: You’re reading a book 📘 and someone signals they want to write notes ✏️. While they’re waiting, another reader 🧑‍🎓 comes.
  
- **Writer-Preference** (like our kernel): The library ensures that those wanting to write are not kept waiting too long because their task might be crucial 📝⏳. So, the new reader also waits, letting the writer go next to avoid delays in noting important updates.

So in techy terms, ensuring writers get priority avoids situations where crucial updates get stuck behind numerous non-disruptive read actions. 🚦🔄
