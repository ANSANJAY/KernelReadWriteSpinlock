# Linux Kernel Synchronization Playground 🛠️🐧

Explore the wonders of **Linux Kernel Module** programming and synchronization mechanisms like **mutexes** and **read-write locks** through practical examples and comprehensive notes.

## Repository Structure 🗂️📚

### [3_read_lock](./3_read_lock/)
- [read_lock.md](./3_read_lock/read_lock.md): Dive into the workings and nuances of utilizing read locks in the Linux kernel.

### [4_order_of_Execution](./4_order_of_Execution/)
- [notes.md](./4_order_of_Execution/notes.md): Uncover insights into the order of execution in kernel programming and synchronization.
- [hello.c](./4_order_of_Execution/hello.c), [ioctl_cmd.h](./4_order_of_Execution/ioctl_cmd.h), [Makefile](./4_order_of_Execution/Makefile): Experiment with kernel module creation and interaction.

### [5_example](./5_example/)
- [hello.c](./5_example/hello.c), [Makefile](./5_example/Makefile): Sample code snippets for kernel module development practice.

### [6_example](./6_example/)
- [hello.c](./6_example/hello.c), [Makefile](./6_example/Makefile): Additional examples for refining your kernel module programming skills.

## Getting Started 🚀

1. **Compile**: Utilize the provided Makefile in each subdirectory.
2. **Load/Unload Modules**: Use `insmod` and `rmmod` for loading and unloading kernel modules respectively.
3. **Explore**: Read the detailed markdown notes and manipulate code snippets to learn interactively.

## License 📄

This project is licensed under the GPL License - see the [LICENSE](./LICENSE) file for details.

👩‍💻 Happy Kernel Hacking! 🚀
