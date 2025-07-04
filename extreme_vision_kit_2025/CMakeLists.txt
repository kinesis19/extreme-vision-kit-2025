cmake_minimum_required(VERSION 3.16)
project(extreme_vision_kit_2025 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# --- 기본 패키지 찾기 ---
find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(ament_cmake REQUIRED)

# --- 스크립트가 의존성 패키지를 찾는 부분을 추가할 위치 ---
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)


set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)

# --- 실행 파일 및 소스 목록 정의 ---
qt_add_executable(${PROJECT_NAME}
    "src/main.cpp"
    "src/mainwindow.cpp"
    "include/extreme_vision_kit_2025/mainwindow.h"
    "ui/mainwindow.ui"
    "resources/images.qrc"
    "src/qnode.cpp"
    "include/extreme_vision_kit_2025/qnode.hpp"
)

# --- 우리 패키지의 헤더 경로 설정 ---
target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# --- 스크립트가 의존성 헤더 경로를 추가할 위치 ---
target_include_directories(${PROJECT_NAME} PRIVATE ${rclcpp_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PRIVATE ${std_msgs_INCLUDE_DIRS})


# --- 라이브러리 링크 ---
target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Widgets
        ${rclcpp_LIBRARIES}
    ${std_msgs_LIBRARIES}

)

# --- 설치 규칙 ---
install(
    TARGETS ${PROJECT_NAME}
    DESTINATION lib/${PROJECT_NAME}
)
install(
    DIRECTORY resources/
    DESTINATION share/${PROJECT_NAME}
)
install(
    DIRECTORY include/
    DESTINATION include
)

# --- 테스트 및 최종 처리 ---
if(BUILD_TESTING)
    find_package(ament_lint_auto REQUIRED)
    ament_lint_auto_find_test_dependencies()
endif()

ament_package()