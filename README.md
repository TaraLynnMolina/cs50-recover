# cs50-recover
A C program that recovers deleted JPEG images from a raw forensic memory card image. Built as part of CS50x (Introduction to Computer Science by Harvard University).

📖 Overview

The program simulates a basic forensic tool used in digital investigations. Given a raw memory card image (binary data), it scans the file block by block, searching for JPEG file signatures. When a signature is found, it reconstructs and saves the JPEG to disk.

This approach is known as file carving and is commonly used in data recovery and forensics.

Example: ./recover card.raw
→ Recovers JPEG images (000.jpg, 001.jpg, 002.jpg, etc.) from the input file.

🛠 Features
	•	Reads raw memory card data in 512-byte blocks.
	•	Detects JPEG file headers by signature bytes.
	•	Recovers multiple images and writes them to new .jpg files.
	•	Handles both single and multiple file recovery.

🚀 How to Run
	1.	Compile the program: make recover
  2.	Run the program with the raw image file: ./recover card.raw
  3.	The recovered JPEG files will be saved in the current directory.

📂 Files
	•	recover.c – main source code
	•	README.md – project documentation
