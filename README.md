# TrusOS

A 32 bit x86 operating system made in Assembly and C from scratch.
<br>

![TrusOS](https://github.com/PrathumP/TrusOS/assets/115390367/32aecbc6-4e32-4f73-8d9c-76472066b181)


## Dependencies 

`xorriso` <br>

`grub` <br>

`GCC Cross Compiler` <br>

## Installation

1. Clone the repository:

   ```
   git clone https://github.com/PrathumP/TrusOS.git
   ```

2. Change to the project directory:

   ```
   cd TrusOS
   ```
3. Run the header build script :
   
   ```
   ./headers.sh
   ```
4. Build the ISO Image:
   
   ```
   ./iso.sh
   ```
5. Run iso on QEMU emulator:
   
   ```
   ./qemu.sh
   ```

If made some changes, remove the previously compiled files by:
   
   ```
   ./clean.sh
   ```
and run the build scripts again.

## Contributing

We welcome contributions to improve the Leetcode Clone project. If you find any issues or have suggestions for new features, please open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT). You are free to use, modify, and distribute the code according to the terms of the license.

