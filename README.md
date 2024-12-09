
The Clinic Management System is designed to streamline administrative tasks and enhance patient care within a medical clinic. It allows both administrators and users to interact with patient records, appointment scheduling, and reservation management. Let’s dive into the details:

# *****  Features:
# * **** Admin Mode:
#Login and Password:
Upon system startup, the user chooses between admin mode and user mode.
In admin mode, the system prompts for a password. The default password is 1234.
The system allows 3 attempts for password entry. After 3 consecutive incorrect attempts, the system closes.
# Add New Patient Record:
# The admin can add a new patient by entering basic information:
Name
Age
Gender
Unique patient ID
If the entered ID already exists, the system rejects the entry.
# Edit Patient Record:
By entering a patient ID, the system checks if the ID exists.
If valid, the admin can edit patient information.
If not, an “incorrect ID” message is displayed.
Reserve a Slot with the Doctor:
# Default available slots: 2pm to 2:30pm, 2:30pm to 3pm, 3pm to 3:30pm, 4pm to 4:30pm, and 4:30pm to 5pm.
Upon opening the slot reservation window, the system displays available slots.
The admin enters the patient ID and selects a desired slot.
Reserved slots are excluded from subsequent patient reservations.
# Cancel Reservation:
The admin can cancel a reservation by entering the patient ID.
The canceled reservation becomes available again in the slots window.
# * **** User Mode:
# View Patient Record:
In user mode (no password required), the user enters a patient ID.
The system displays basic patient information.
# View Today’s Reservations:
The system prints all reservations for the current day.
Each reservation includes the patient ID.
This Clinic Management System aims to improve efficiency, reduce paperwork, and enhance patient care.
