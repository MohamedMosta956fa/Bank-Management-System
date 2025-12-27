Bank Management System (OOP)
A robust, console-based Banking Management System developed in C++ using Object-Oriented Programming (OOP) principles. This project focuses on high-security standards through a permission-based user system and follows a structured software architecture.

🚀 Key Features
• Role-Based Access Control (RBAC): A sophisticated permission system that verifies user rights before granting access to specific modules (e.g., Client List, Transactions, or Admin Tools).

• Client Management (CRUD): Complete system to Create, Read, Update, and Delete client records with unique account numbers.

• Transaction System: Supports core banking operations:

  • Deposits & Withdrawals.

  • Total Balances reporting.

  • Transfer operations between accounts.

• User Management: An administrative layer to manage system operators, including setting their specific access flags/permissions.

• Data Persistence: All data is securely stored and retrieved from flat files (`.txt`), ensuring information is saved between sessions.

🛠️ Technical Highlights
• OOP Principles: Extensive use of Inheritance, Encapsulation, and Polymorphism to ensure code reusability and modularity.

• Layered Architecture: Clear separation between the Logic Layer (Core functionality) and the Presentation Layer (Console UI).

• Permissions Logic: Implemented using Bitwise operations (or integer-based flags) to efficiently manage complex access levels.

• Advanced File Handling: Efficiently parsing and updating data files using C++ File Streams (`fstream`).

💻 How to Run
1. Clone the repository to your local machine.

2. Open the project in any C++ IDE (e.g., Visual Studio, Code::Blocks, or CLion).

3. Ensure the `.txt` data files (Clients, Users) are in the same directory as the executable.

4. Build and run the project.

5. Default Login: (Use the admin credentials you set in your code, e.g., Admin/1234).

