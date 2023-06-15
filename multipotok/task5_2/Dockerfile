FROM ubuntu:latest
LABEL mantainer="79057778281@ya.ru"
RUN apt-get update && apt-get -y install g++ nano net-tools inetutils-ping
WORKDIR /root/test
COPY task1.cpp .
RUN g++ task1.cpp -o task1
CMD ["./task1"]