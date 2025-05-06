#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    char message[] = "Hello, file!\n";

    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    write(fd, message, sizeof(message) - 1);
    close(fd);
    return 0;
}

