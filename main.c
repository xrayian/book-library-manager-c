#include <stdio.h>
#include <string.h>

// structures
struct Book
{
    char title[100];
    char author[100];
    double ISBN;
    int available;
};

struct Library
{
    struct Book books[100];
    int totalBookCount;
    int availableBookCount;
};

// user defined functions
void trim(char s[]);
void addNewBook(struct Library *libPtr);
void issueBook(struct Library *libPtr);
void returnBook(struct Library *libPtr);
void showBookList(struct Library *libPtr);
struct Library loadLibrary();

int main()
{
    struct Library lib = loadLibrary();
    printf("Welcome to library manager v0.1\n\nSelect your operation\n");
    while (1)
    {
        printf("A(dd) | I(ssue) | R(eturn) | L(ist)\n> ");
        char input = '\0';
        fflush(stdin);
        scanf(" %c", &input);
        if (input == 'A' || input == 'a')
        {
            addNewBook(&lib);
        }
        else if (input == 'I' || input == 'i')
        {
            issueBook(&lib);
        }
        else if (input == 'R' || input == 'r')
        {
            returnBook(&lib);
        }
        else if (input == 'L' || input == 'l')
        {
            showBookList(&lib);
        }
        else
        {
            printf("Invalid Choice, Please try again.");
        }
        printf("\n\n");
    }
}

void trim(char s[])
{
    //? for getting rid of the '\n' at the end of fgets;
    int x = strlen(s) - 1;
    if (s[x] == '\n')
    {
        s[x] = '\0';
    }
}

struct Library loadLibrary()
{
    struct Library lib = {
        {
            {"The Fault in our stars", "John Green", 9780143567592, 1},
            {"Pride and Prejudice", "Jane Austen", 9780141439518, 1},
            {"The Lord of the Rings", "J.R.R. Tolkien", 9780547928227, 1},
            {"To Kill a Mockingbird", "Harper Lee", 9780425193880, 1},
            {"1984", "George Orwell", 9780451524935, 1},
            {"The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 9780345391803, 1},
            {"The Great Gatsby", "F. Scott Fitzgerald", 9780747531185, 1},
            {"Harry Potter and the Sorcerer's Stone", "J.K. Rowling", 9780590353427, 1},
            {"The Hunger Games", "Suzanne Collins", 9780439023481, 1},
            {"The Book Thief", "Markus Zusak", 9780375831003, 1},
            {"The Alchemist", "Paulo Coelho", 9780061122415, 1},
            {"The Adventures of Sherlock Holmes", "Arthur Conan Doyle", 9780141441404, 1},
            {"Moby Dick", "Herman Melville", 9780140390642, 1},
            {"Jane Eyre", "Charlotte Bronte", 9780141439044, 1},
            {"Little Women", "Louisa May Alcott", 9780141439754, 1},
            {"The Picture of Dorian Gray", "Oscar Wilde", 9780141442487, 1},
            {"Dune", "Frank Herbert", 9780441172719, 1},
            {"Ender's Game", "Orson Scott Card", 9780812550702, 1},
            {"The Handmaid's Tale", "Margaret Atwood", 9780385490818, 1},
            {"Neuromancer", "William Gibson", 9780441569560, 1},
            {"The Martian", "Andy Weir", 9780804139021, 1},
            {"The Kite Runner", "Khaled Hosseini", 9781594480003, 1},
            {"Beloved", "Toni Morrison", 9781400033416, 1},
            {"The God of Small Things", "Arundhati Roy", 9780060977497, 1},
            {"Gone Girl", "Gillian Flynn", 9780307588371, 1},
            {"The Secret History", "Donna Tartt", 9780679750296, 1},
            {"The Name of the Wind", "Patrick Rothfuss", 9780756404741, 1},
            {"A Song of Ice and Fire", "George R. R. Martin", 9780553103540, 1},
            {"The Color Purple", "Alice Walker", 9780156028356, 1},
            {"Catch-22", "Joseph Heller", 9780684833395, 1},
            {"Invisible Man", "Ralph Ellison", 9780679732761, 1},
        },
        31,
        31,
    };
    return lib;
}

void issueBook(struct Library *libPtr)
{
    showBookList(libPtr);
    fflush(stdin);
    printf("Enter Book Serial No: ");
    int index;
    scanf("%d", &index);

    if (libPtr->books[index - 1].available)
    {
        libPtr->books[index - 1].available = 0;
        printf("'%s' Issued Successfully!\n", libPtr->books[index - 1].title);
        libPtr->availableBookCount--;
    }
    else
    {
        printf("'%s' is not available at the moment.\n", libPtr->books[index - 1].title);
    }
}

void returnBook(struct Library *libPtr)
{
    showBookList(libPtr);
    fflush(stdin);
    printf("Enter Book Serial No: ");
    int index;
    scanf("%d", &index);

    if (!libPtr->books[index - 1].available)
    {
        libPtr->books[index - 1].available = 1;
        printf("'%s' Returned Successfully.\n", libPtr->books[index - 1].title);
        libPtr->availableBookCount++;
    }
    else
    {
        printf("'%s' has not been issued yet.\n", libPtr->books[index - 1].title);
    }
}

void addNewBook(struct Library *libPtr)
{
    fflush(stdin);
    int bookCount = libPtr->totalBookCount;
    printf("Enter Book Title: ");
    fgets(libPtr->books[bookCount].title, 100, stdin);
    trim(libPtr->books[bookCount].title);
    printf("Enter Book Author: ");
    fgets(libPtr->books[bookCount].author, 100, stdin);
    trim(libPtr->books[bookCount].author);
    printf("Enter Book ISBN: ");
    scanf("%lf", &libPtr->books[bookCount].ISBN);
    libPtr->books[bookCount].available = 1;
    libPtr->totalBookCount++;
    libPtr->availableBookCount++;
    printf("Book Added Successfully\n");
}

void showBookList(struct Library *libPtr)
{
    printf("Listing All Books\nTotal: %d | Available: %d\n", libPtr->totalBookCount, libPtr->availableBookCount);
    printf("%s\t%s\t\t\t%60s\n", "Sl.", "Title", "Author");
    printf("====\t===========================================\t\t\t====================\n");
    int bookCount = libPtr->totalBookCount; // note to self Size of returns bytes.
    for (int i = 0; i < bookCount; i++)
    {
        if (strlen(libPtr->books[i].title) > 1)
        {
            if (libPtr->books[i].available)
            {
                printf("%4d. %45s\t\t\t%20s\n", i + 1, libPtr->books[i].title, libPtr->books[i].author);
            }
            else
            {
                printf("%4d. %30s(Not Available)\t\t\t%20s\n", i + 1, libPtr->books[i].title, libPtr->books[i].author);
            }
        }
    }
}
