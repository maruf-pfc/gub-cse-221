#!/bin/bash

display_menu() {
    echo "Note Management System"
    echo "1. Create Note"
    echo "2. Read Note"
    echo "3. Update Note"
    echo "4. Delete Note"
    echo "5. Exit"
}

create_note() {
    echo "Enter note content:"
    read content

    filename=$(date +"%Y-%m-%d_%H-%M-%S").md

    echo "# Note" > "$filename"
    echo "$content" >> "$filename"

    echo "Note created: $filename"
}

read_note() {
    echo "Enter note filename (YYYY-MM-DD_HH-MM-SS.md):"
    read filename

    if [[ -f "$filename" ]]; then
        cat "$filename"
    else
        echo "Note not found"
    fi
}

update_note() {
    echo "Update Note is not supported with this storage method."
}

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

main() {
    while true; do
        display_menu
        echo "Choose an option:"
        read choice

        case $choice in
            1) create_note ;;
            2) read_note ;;
            3) update_note ;;
            4) delete_note ;;
            5) echo "Exiting..." && exit 0 ;;
            *) echo "Invalid choice" ;;
        esac
    done
}

main
