import os

def enchant_files():
    current_realm = os.getcwd()  # Gets the current realm of execution
    scrolls = os.listdir(current_realm)  # Lists all the scrolls and artifacts in the realm

    for scroll in scrolls:
        if scroll.endswith('.c'):  # Check if the scroll is of the .c kind
            enchanted_scroll = 'ft_' + scroll  # Bestow the 'ft_' prefix
            os.rename(scroll, enchanted_scroll)  # Rename the scroll

    print("The enchantment is complete, the .c scrolls have been marked.")

if __name__ == "__main__":
    enchant_files()  # Call the enchantment ritual
