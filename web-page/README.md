## File Structure

MVC Design Pattren

- Model: The model represents the data and business logic of the application. It is responsible for managing the data and performing operations on it.
- View: The view is responsible for displaying the data to the user. It is typically implemented using HTML and CSS.
- Controller: The controller is responsible for handling user input and updating the model accordingly. It is typically implemented using a server-side programming language such as PHP, Java, or Python.

MVC advantages
- Separation of concerns: MVC separates the application into three distinct components, which makes it easier to develop and maintain the application.
- Testability: MVC makes it easier to test the application by isolating the different components.
- Reusability: MVC components can be reused in other applications, which saves time and effort.

        ├── app
        |  ├── models
        |  ├── view
        |  |  ├── include
        |  |  |  ├── header.inc
        |  |  |  ├── footer.inc
        |  |  |  ├── initialization.inc
        |  |  |  ├── language.inc
        |  |  ├── logo
        |  |  |  ├── favicon.svg
        |  |  ├── public
        |  |  |  ├── scan
        |  |  |  |  ├── access_point.php
        |  |  |  |  ├── station.php
        |  |  |  ├── attack
        |  |  |  |  ├── wifi
        |  |  |  |  ├── usb
        |  |  |  ├── info.inc
        |  |  ├── src
        |  |  |  ├── script
        |  |  |  |  ├── script.js
        |  |  |  ├── style	
        |  |  |  |  ├── style.css
        |  |  |  |  ├── initialization.css
        |  |  |  |  ├── animation.css
        |  |  |  ├── screen
        |  |  |  |  ├── iphone.css
        |  |  |  |  ├── ipad.css
        |  ├── controllers
        |  |  ├── components
        |  |  |  ├── span.inc
        |  |  |  ├── button.inc
        |  |  |  ├── div.inc
        |  |  |  ├── img.inc
        |  |  |  ├── form.inc
        |  |  |  ├── input.inc
        |  |  |  ├── button.inc
        |  |  |  ├── table.inc
        |  |  |  ├── components.php
        |  |  ├── api
        |  |  |  ├── get
        |  |  |  |  ├── get_scan.php
        |  |  |  |  ├── get_attack.php
        |  |  |  ├── post
        |  |  |  |  ├── post_scan.php
        |  |  |  |  ├── post_attack.php
        ├──index.php



## Color Reference

Dark/Light Mode

This mode provides the ability to customize the user experience to the surrounding environment using dark mode to reduce emissions and to maintain eye comfort and using light mode when needed to see content more clearly

| Color             | Hex                                                                |
| ----------------- | ------------------------------------------------------------------ |
| Primary Text Color Dark | ![#dc3545](https://via.placeholder.com/10/dc3545?text=+) #dc3545 |
| Secondary Text Color Dark | ![#f8f9fa](https://via.placeholder.com/10/f8f9fa?text=+) #f8f9fa |
| Dark Theme Color 1 | ![#495057](https://via.placeholder.com/10/495057?text=+) #495057 |
| Dark Theme Color 2 | ![#343a40](https://via.placeholder.com/10/343a40?text=+) #343a40 |
| Dark Theme Color 3 | ![#212529](https://via.placeholder.com/10/212529?text=+) #212529 |
| Secondary Text Color Light | ![#495057](https://via.placeholder.com/10/495057?text=+) #495057 |
| Light Theme Color 1 | ![#e9ecef](https://via.placeholder.com/10/e9ecef?text=+) #e9ecef |
| Light Theme Color 2 | ![#f8f9fa](https://via.placeholder.com/10/f8f9fa?text=+) #f8f9fa |
| Light Theme Color 3 | ![#dee2e6](https://via.placeholder.com/10/dee2e6?text=+) #dee2e6 |


## Tech Stack

Client

- Routing page
- long polling

Server

- Routing path
- Cron Job


