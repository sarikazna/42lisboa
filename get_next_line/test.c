#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char *get_next_line(int fd) {
    char *buf = NULL;
    size_t buf_size = 10;
    size_t count = 0;
    ssize_t bytes_read;
	
    if (fd == -1)
        return NULL;

    buf = (char *)malloc(buf_size);
    if (buf == NULL)
        return NULL;

    while (1) {
        bytes_read = read(fd, buf + count, buf_size - count);
        if (bytes_read == -1) {
            free(buf);
            return NULL;
        } else if (bytes_read == 0) {
            break;  // End of file
        }

        count += bytes_read;

        if (count == buf_size) {
            // Buffer full, need to allocate more memory
            buf_size *= 2;
            char *new_buf = (char *)malloc(buf_size);
            if (new_buf == NULL) {
                free(buf);
                return NULL;
            }
            // Copy the existing contents to the new buffer
            for (size_t i = 0; i < count; i++) {
                new_buf[i] = buf[i];
            }
            free(buf);
            buf = new_buf;
        }
    }

    buf[count] = '\0';
    printf("Read line: %s\n\n", buf);
    return buf;
}

int main(void) {
    int fd;
    fd = open("paragraph_file.txt", O_RDONLY);
    char *line = get_next_line(fd);
    if (line != NULL) {
        // Use the line as needed
        // ...

        free(line);  // Free the allocated memory
    }
    return 0;
}