 #include <stdio.h>
 struct pstruct {
    int fno;
    int pbit;
 } ptable[10];
 int pmsize, lmsize, psize, frame, page, ftable[20], frameno;
 void info() {
    printf("\nMEMORY MANAGEMENT USING PAGING\n");
    printf("\nEnter the Size of Physical memory: ");
    scanf("%d", &pmsize);
    printf("\nEnter the size of Logical memory: ");
    scanf("%d", &lmsize);
    printf("\nEnter the partition size: ");
    scanf("%d", &psize);
    frame = pmsize / psize;
    page = lmsize / psize;
    printf("\nThe physical memory is divided into %d frames\n", frame);
    printf("The Logical memory is divided into %d pages\n", page);
 }
 void assign() {
    int i;
    for (i = 0; i < page; i++) {
        ptable[i].fno = -1;
        ptable[i].pbit = -1;
    }
    for (i = 0; i < frame; i++)
        ftable[i] = -1;  // Changed 32555 to -1 for invalid frame
    for (i = 0; i < page; i++) {
        printf("\nEnter the Frame number where page %d must be placed: ", i);
        scanf("%d", &frameno);
        if (frameno >= frame || frameno < 0) {
            printf("Invalid frame number! Try again.\n");
            i--;
            continue;
        }
        ftable[frameno] = i;
        if (ptable[i].pbit == -1) {
            ptable[i].fno = frameno;
            ptable[i].pbit = 1;
        }
    }
    printf("\nPAGE TABLE\n");
    printf("Page Address  Frame No. Presence Bit\n");
    for (i = 0; i < page; i++)
        printf("%d\t\t%d\t\t%d\n", i, ptable[i].fno, ptable[i].pbit);
    printf("\nFRAME TABLE\n");
    printf("Frame Address  Page No\n");
    for (i = 0; i < frame; i++)
        printf("%d\t\t%d\n", i, ftable[i]);
 }
 void cphyaddr() {
    int laddr, paddr, disp, phyaddr, baddr;
    printf("\nProcess to create the Physical Address\n");
    printf("\nEnter the Base Address: ");
    scanf("%d", &baddr);
    printf("\nEnter the Logical Address: ");
    scanf("%d", &laddr);
    paddr = laddr / psize;
    disp = laddr % psize;
    if (paddr >= page || ptable[paddr].pbit == -1) {
        printf("\nInvalid logical address or page not in memory.\n");
        return;
    }
    phyaddr = baddr + (ptable[paddr].fno * psize) + disp;
    printf("\nThe Physical Address where the instruction is present: %d\n", phyaddr);
 }
 int main() {
    info();
    assign();
    cphyaddr();
    return 0;
}