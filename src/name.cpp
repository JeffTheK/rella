#include "name.hpp"
#include "../include/json.hpp"
#include <vector>
#include <fstream>

static std::vector<std::string> names;

Name Name::load_from_json(json component_json) {
    auto name = component_json["name"].get<std::string>();
    
    return Name{name};
}

void Name::load_random_names() {
    std::ifstream file;
    file.open("data/names.json", std::ios::in);
    assert(file.is_open());
    std::string text = "";
    std::string line = "";
    while(std::getline(file, line)) {
        text += line;
    }
    auto names_json = nlohmann::json::parse(text)["names"];
    for (auto& name : names_json) {
        names.push_back(name.get<std::string>());
    }
    file.close();
}

