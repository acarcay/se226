import random
import string


def main():
    letter_replacements = {}
    all_replacements = set()

    print("Choose 5 lowercase letters and assign 3 replacement characters to each:")

    for _ in range(5):
        while True:
            letter = input("Enter a lowercase letter: ").lower()
            if len(letter) != 1 or letter not in string.ascii_lowercase:
                print("Please enter a single lowercase letter.")
                continue
            if letter in letter_replacements:
                print(f"You've already chosen '{letter}'. Please choose a different letter.")
                continue
            break

        replacements = set()
        letter_replacements[letter] = []

        for i in range(3):
            while True:
                replacement = input(f"Enter replacement #{i + 1} for '{letter}': ")
                if len(replacement) != 1:
                    print("Please enter a single character.")
                    continue
                if replacement in all_replacements:
                    print("This replacement is already used. Please choose a different one.")
                    continue
                if replacement in replacements:
                    print("You've already assigned this replacement to the current letter.")
                    continue
                break

            replacements.add(replacement)
            all_replacements.add(replacement)
            letter_replacements[letter].append(replacement)

    passwords = generate_passwords(10, 15)  # Generate 10 passwords of length 15
    modified_passwords = []

    for password in passwords:
        modified = apply_replacements(password, letter_replacements)
        modified_passwords.append(modified)

    categorized_passwords = {"strong": [], "weak": []}

    for original, modified in zip(passwords, modified_passwords):
        replacement_count = sum(1 for a, b in zip(original, modified) if a != b)

        if replacement_count > 4:
            categorized_passwords["strong"].append(modified)
        else:
            categorized_passwords["weak"].append(modified)

    print("\nGenerated Passwords:")
    print("STRONG PASSWORDS:")
    for password in categorized_passwords["strong"]:
        print(password)

    print("\nWEAK PASSWORDS:")
    for password in categorized_passwords["weak"]:
        print(password)

    print("\nBONUS - Categorized by special characters:")
    bonus_categorized = categorize_by_special_chars(modified_passwords, all_replacements)

    print("STRONG PASSWORDS (> 4 special characters):")
    for password in bonus_categorized["strong"]:
        print(password)

    print("\nWEAK PASSWORDS (<= 4 special characters):")
    for password in bonus_categorized["weak"]:
        print(password)


def generate_passwords(num, length):
    passwords = []
    for _ in range(num):
        password = ''.join(random.choice(string.ascii_lowercase) for _ in range(length))
        passwords.append(password)
    return passwords


def apply_replacements(password, letter_replacements):
    result = ""
    for char in password:
        if char in letter_replacements:
            result += random.choice(letter_replacements[char])
        else:
            result += char
    return result


def categorize_by_special_chars(passwords, special_chars):
    categorized = {"strong": [], "weak": []}

    for password in passwords:
        special_count = sum(1 for char in password if char in special_chars)
        if special_count > 4:
            categorized["strong"].append(password)
        else:
            categorized["weak"].append(password)

    return categorized


if __name__ == "__main__":
    main()
