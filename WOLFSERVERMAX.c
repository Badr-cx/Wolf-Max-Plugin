#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NCAM_SERVER_PATH "/data/plugin/wolf_cam/ncam.server"
#define DROPBOX_URL "https://www.dropbox.com/scl/fi/jop020u2lzwbk6x02i8vc/ncam.server?rlkey=oq59ownodge0xnkvilo3s5d36&st=rehiwaw2&dl=1"

int main() {
    char command[512];
    sprintf(command, "wget -q --no-check-certificate -O %s \"%s\"", NCAM_SERVER_PATH, DROPBOX_URL);
    while(1) {
        int result = system(command);
        if (result == 0) {
            system("killall -9 ncam 2>/dev/null");
            system("/data/plugin/wolf_cam/ncam -b -c /data/plugin/wolf_cam &");
        }
        sleep(600);
    }
    return 0;
}
