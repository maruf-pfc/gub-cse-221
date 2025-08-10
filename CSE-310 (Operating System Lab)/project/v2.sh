#!/bin/bash

# Admin credentials file
admin_credentials_file="admin_credentials.txt"

# Function to display menu options
display_menu() {
    echo "Note Management System"
    echo "1. Create Note"
    echo "2. Read Note"
    echo "3. Update Note"
    echo "4. Delete Note"
    echo "5. Exit"
}

# Function to create a new note
create_note() {
    echo "Enter note content:"
    read content

    # Generate filename with current date and time
    filename=$(date +"%Y-%m-%d_%H-%M-%S").md

    # Format note content in markdown syntax
    echo "# Note" > "$filename"
    echo "$content" >> "$filename"

    echo "Note created: $filename"
}

# Function to read a note
read_note() {
    echo "Enter note filename (YYYY-MM-DD_HH-MM-SS.md):"
    read filename

    if [[ -f "$filename" ]]; then
        cat "$filename"
    else
        echo "Note not found"
    fi
}

# Function to delete a note
delete_note() {
    echo "Enter note filename (YYYY-MM-DD_HH-MM-SS.md):"
    read filename

    if [[ -f "$filename" ]]; then
        rm "$filename"
        echo "Note deleted: $filename"
    else
        echo "Note not found"
    fi
}

# Function to register admin
register_admin() {
    echo "Admin registration"
    echo "Enter username:"
    read username

    # Check if username already exists
    if grep -q "^$username:" "$admin_credentials_file"; then
        echo "Username already exists."
        return
    fi

    echo "Enter password:"
    read -s password
    echo ""

    # Hash password
    hashed_password=$(echo -n "$password" | sha256sum | awk '{print $1}')

    # Save credentials
    echo "$username:$hashed_password" >> "$admin_credentials_file"
    echo "Admin registered successfully."
}

# Function to login as admin
admin_login() {
    echo "Admin Login"
    echo "Enter username:"
    read username
    echo "Enter password:"
    read -s password
    echo ""

    # Hash password
    hashed_password=$(echo -n "$password" | sha256sum | awk '{print $1}')

    # Check credentials
    if grep -q "^$username:$hashed_password" "$admin_credentials_file"; then
        echo "Login successful."
    else
        echo "Invalid credentials."
        exit 1
    fi
}

# Main function
main() {
    # Check if admin credentials file exists, if not create it
    if [[ ! -e "$admin_credentials_file" ]]; then
        touch "$admin_credentials_file"
    fi

    # Check if admin is registered, if not prompt for registration
    if ! grep -q ":" "$admin_credentials_file"; then
        echo "Admin not registered."
        register_admin
    fi

    # Admin login
    admin_login

    while true; do
        display_menu
        echo "Choose an option:"
        read choice

        case $choice in
            1) create_note ;;
            2) read_note ;;
            3) echo "Update Note is not supported with this storage method." ;;
            4) delete_note ;;
            5) echo "Exiting..." && exit 0 ;;
            *) echo "Invalid choice" ;;
        esac
    done
}

# Start the program
main
