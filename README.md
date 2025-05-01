# JSON 예제 프로젝트

이 프로젝트는 C++에서 nlohmann/json 라이브러리를 사용하는 예제 프로젝트입니다.

## 필수 요구사항

- C++ 컴파일러 (MinGW)
- CMake (최소 버전 3.10)
- vcpkg 패키지 매니저
- nlohmann/json 라이브러리 (vcpkg를 통해 설치)

## 설치 방법

1. vcpkg를 통해 nlohmann/json 라이브러리 설치:

```bash
vcpkg install nlohmann-json:x64-windows
```

2. 프로젝트 클론 또는 다운로드

## 빌드 방법

Windows 환경에서는 포함된 `build.bat` 스크립트를 실행하시면 됩니다:

```bash
build.bat
```

이 스크립트는 다음 작업을 수행합니다:
- 이전 빌드 결과물 정리 (build 디렉토리 삭제)
- CMake를 사용하여 프로젝트 구성
- 프로젝트 빌드
- 빌드된 실행 파일 자동 실행

## 프로젝트 구조

- `main.cpp` - 메인 소스 코드
- `CMakeLists.txt` - CMake 빌드 설정
- `build.bat` - 빌드 자동화 스크립트
- `vcpkg.json` - vcpkg 매니페스트

## 라이선스

이 프로젝트는 MIT 라이선스 하에 배포됩니다. 