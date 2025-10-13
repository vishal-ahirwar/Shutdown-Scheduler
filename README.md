

# As Timer

A simple and elegant PC shutdown and restart scheduler built with C++ and QML.


-----

## About The Project

**As Timer** is a minimalist desktop utility designed to do one thing well: schedule your computer to automatically shut down or restart. Set a timer, choose an action, and let the app handle the rest. Its clean, modern interface ensures a straightforward user experience without unnecessary clutter.

<table>
  <tr>
    <td><img src="https://github.com/user-attachments/assets/c9011bba-e7c1-4412-a297-420a57410062" alt="Image 1" width="300"/></td>
    <td><img src="https://github.com/user-attachments/assets/08b4fb7f-5b12-49ca-b5d5-3ce3d9c82deb" alt="Image 2" width="300"/></td>
  </tr>
  <tr>
    <td><img src="https://github.com/user-attachments/assets/462a9abd-4955-45b4-8510-d327cbdcbc8d" alt="Image 3" width="300"/></td>
  </tr>
</table>

## Features

  * **Schedule Shutdowns:** Set a timer to automatically shut down your PC.
  * **Schedule Restarts:** Configure a timer to restart your system when needed.
  * **Intuitive Timer Input:** Easily specify the delay in minutes.
  * **Modern UI:** A sleek, dark-themed interface built with QML.
  * **Conflict Warning:** The app intelligently warns you if a shutdown or restart is already scheduled, preventing conflicts.

-----

## Technologies Used

  * **Backend:** C++
  * **Frontend:** QML (Qt Quick)
  * **Framework:** Qt 6

-----

## Getting Started

### Prerequisites

  * A C++ compiler (MSVC, GCC, or Clang)
  * Qt 6.x (with Qt Quick Controls)
  * CMake 3.16 or higher

### Build From Source

1.  **Clone the repository:**

    ```bash
    git clone https://github.com/your-username/as-timer.git
    cd as-timer
    ```

2.  **Configure the project with CMake:**

    ```bash
    cmake -B build
    ```

3.  **Build the application:**

    ```bash
    cmake --build build --config Release
    ```

4.  **Run the executable:**
    The final executable will be located in the `build` directory.

-----

## License

This project is licensed under the MIT License. See the `LICENSE` file for more details.

