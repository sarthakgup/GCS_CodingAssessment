import requests #need to pip install requests

API_KEY = "566d38afd97a96811892be92a8056eb9"  #OpenWeather API key
favorites = []  #memory

def get_weather(city):
    url = f"https://api.openweathermap.org/data/2.5/weather?q={city}&appid={API_KEY}&units=imperial"
    
    try:
        response = requests.get(url)
        data = response.json()

        if response.status_code != 200 or "main" not in data:
            return f"Error: {data.get('message', 'Unable to fetch weather.')}"
        
        temp = data['main']['temp']
        description = data['weather'][0]['description'].capitalize()

        return f"{description}, {temp}°F"
    except requests.RequestException as e:
        return f"Error: {e}"

def print_favorites():
    print("\nFavorite Cities:")

    if not favorites:
        print("  None")
    else:
        for city in favorites:
            print(f"  {city}: {get_weather(city)}")

def update_favorite():
    print_favorites()
    to_replace = input("Enter the name of the city you'd like to replace: ").strip()
    if to_replace not in favorites:
        print("City not found in favorites.")
        return
    new_city = input("Enter the new city to add: ").strip()
    index = favorites.index(to_replace)
    favorites[index] = new_city
    print(f"{to_replace} replaced with {new_city}.\n")

def main():
    while True:
        print("\nType a city name to get weather (or 'update' to modify favorites, 'exit' to quit):")
        city = input("> ").strip()
        
        if city.lower() == "exit":
            break
        elif city.lower() == "update":
            if favorites:
                update_favorite()
            else:
                print("No favorites to update.")
            continue

        weather = get_weather(city)
        print(f"Weather in {city}: {weather}")

        add_fav = input("Would you like to add this city to your favorites? (yes/no): ").strip().lower()
        if add_fav == "yes":
            if city in favorites:
                print("City is already in favorites.")
            elif len(favorites) < 3:
                favorites.append(city)
                print(f"{city} added to favorites.")
            else:
                print("You already have 3 favorites.")
                replace = input("Would you like to replace one? (yes/no): ").strip().lower()
                if replace == "yes":
                    update_favorite()

        print_favorites()

    print("Goodbye!")

if __name__ == "__main__":
    main()



