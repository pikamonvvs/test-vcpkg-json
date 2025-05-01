#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include <string>

using json = nlohmann::json;

int main()
{
    try
    {
        // JSON 생성
        json config;
        config["name"] = "JSON 예제";
        config["version"] = 1.0;

        // 배열 추가
        config["languages"] = {"C++", "Python", "JavaScript"};

        // 중첩된 객체 추가
        config["database"] = {
            {"host", "localhost"},
            {"port", 5432},
            {"name", "test_db"}};

        // JSON을 문자열로 출력
        std::cout << "생성된 JSON:\n"
                  << config.dump(2) << "\n\n";

        // JSON을 파일로 저장
        std::ofstream fout("config.json");
        fout << config.dump(4);
        fout.close();
        std::cout << "config.json 파일이 생성되었습니다.\n\n";

        // JSON 파일 읽기
        std::ifstream fin("config.json");
        json loaded_config = json::parse(fin);

        // 데이터 접근
        std::cout << "파일에서 읽은 데이터:\n";
        std::cout << "이름: " << loaded_config["name"] << "\n";
        std::cout << "버전: " << loaded_config["version"] << "\n";

        std::cout << "지원 언어:\n";
        for (const auto &lang : loaded_config["languages"])
        {
            std::cout << "- " << lang << "\n";
        }

        std::cout << "\n데이터베이스 설정:\n";
        std::cout << "호스트: " << loaded_config["database"]["host"] << "\n";
        std::cout << "포트: " << loaded_config["database"]["port"] << "\n";
        std::cout << "DB 이름: " << loaded_config["database"]["name"] << "\n";
    }
    catch (const json::exception &e)
    {
        std::cerr << "JSON 오류: " << e.what() << "\n";
        return 1;
    }

    return 0;
}