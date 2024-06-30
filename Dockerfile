# 使用 Ubuntu 作為基礎映像
FROM ubuntu:20.04

# 設置環境變量以避免手動交互
ENV DEBIAN_FRONTEND=noninteractive

# 安裝必要的工具和依賴
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    wget \
    libgtest-dev \
    tzdata \
    && apt-get clean

# 設定時區
RUN ln -fs /usr/share/zoneinfo/Asia/Taipei /etc/localtime && dpkg-reconfigure --frontend noninteractive tzdata

# 安裝 Google Test
RUN cd /usr/src/googletest && \
    cmake . && \
    make && \
    cp lib/libgmock.a lib/libgmock_main.a lib/libgtest.a lib/libgtest_main.a /usr/lib/

# 設定工作目錄
WORKDIR /app

# 複製 CMake 配置文件和源文件到工作目錄
COPY . .

# 移除可能存在的 build 目錄並建立新的構建目錄
RUN rm -rf build && mkdir build

# 設定構建目錄
WORKDIR /app/build

# 編譯 C++ 專案
RUN cmake .. && make

# 設定容器的執行命令
CMD ["./app"]