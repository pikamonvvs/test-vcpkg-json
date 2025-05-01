#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include <string>

using json = nlohmann::json;

int main()
{
    try
    {
        // Create JSON
        json config;
        config["name"] = "JSON Example";
        config["version"] = 1.0;

        // Add array
        config["languages"] = {"C++", "Python", "JavaScript"};

        // Add nested object
        config["database"] = {
            {"host", "localhost"},
            {"port", 5432},
            {"name", "test_db"}};

        // Print JSON as string
        std::cout << "Generated JSON:\n"
                  << config.dump(2) << "\n\n";

        // Save JSON to file
        std::ofstream fout("config.json");
        fout << config.dump(4);
        fout.close();
        std::cout << "config.json file has been created.\n\n";

        // Read JSON file
        std::ifstream fin("config.json");
        json loaded_config = json::parse(fin);

        // Access data
        std::cout << "Data read from file:\n";
        std::cout << "Name: " << loaded_config["name"] << "\n";
        std::cout << "Version: " << loaded_config["version"] << "\n";

        std::cout << "Supported languages:\n";
        for (const auto &lang : loaded_config["languages"])
        {
            std::cout << "- " << lang << "\n";
        }

        std::cout << "\nDatabase settings:\n";
        std::cout << "Host: " << loaded_config["database"]["host"] << "\n";
        std::cout << "Port: " << loaded_config["database"]["port"] << "\n";
        std::cout << "DB Name: " << loaded_config["database"]["name"] << "\n";
    }
    catch (const json::exception &e)
    {
        std::cerr << "JSON Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}