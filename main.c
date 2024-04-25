#include <stdio.h>
#include <string.h>

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

void showBookList(struct Library *libPtr)
{
    printf("Listing All Available Books\n\n");
    printf("%s\t%s\t\t\t%60s\n", "Sl.", "Title", "Author");
    printf("====\t===========================================\t\t\t====================\n");
    int bookCount = libPtr->totalBookCount; // note to self Size of returns bytes.
    for (int i = 0; i < bookCount; i++)
    {
        if (strlen(libPtr->books[i].title) > 1)
            printf("%4d. %45s\t\t\t%20s\n", i + 1, libPtr->books[i].title, libPtr->books[i].author);
    }
}

int main()
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
            {"Jane Eyre", "Charlotte Brontë", 9780141439044, 1},
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
    };
    printf("Welcome to library manager v0.1\n\n");
    printf("Select your operation\nA(dd) | I(ssue) | R(eturn) | L(ist)\n> ");
    char input = '\0';
    scanf("%c", &input);
    switch (input)
    {
    case 'A':
        printf("Add New Book\n");
        break;

    case 'I':
        printf("Issue Book to user\n");
        break;

    case 'R':
        printf("Return Book to the library\n");
        break;

    case 'L':
        showBookList(&lib);
        break;

    default:
        break;
    }
}
