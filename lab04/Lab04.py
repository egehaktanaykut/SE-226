users = dict()
num_users = int(input("Enter the number of users: "))

for _ in range(num_users):
    username = input("Enter username: ")
    num_items = int(input(f"How many items does {username} want to enter? "))
    items = []
    for _ in range(num_items):
        item = input("Enter item name: ")
        items.append(item)
    users[username] = items

print(users)

item_users = dict()

for user, items in users.items():
    for item in set(items):
        if item not in item_users:
            item_users[item] = set()
        item_users[item].add(user)

common_items = [item for item, u_set in item_users.items() if len(u_set) > 1]
unique_items = [item for item, u_set in item_users.items() if len(u_set) == 1]

max_count = max(len(u_set) for u_set in item_users.values())
most_popular = [item for item, u_set in item_users.items() if len(u_set) == max_count]

print("Common items:", common_items)
print("Unique items:", unique_items)
print("Most popular item(s):", most_popular)