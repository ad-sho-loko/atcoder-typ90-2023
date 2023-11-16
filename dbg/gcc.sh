# 未定義動作（配列外アクセスなど）のデバッグをする場合
g++ Main.cpp --std=c++20 -fsanitize=undefined -Wall

## より詳細にデバッグする場合
g++ Main.cpp --std=c++20 -fsanitize=undefined,address -D_GLIBCXX_DEBUG -Wall

## 全部盛り
g++ Main.cpp --std=c++20 -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector

