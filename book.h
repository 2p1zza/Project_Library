#ifndef BOOK_H
#define BOOK_H

#include <QString>
#include <QDate>
#include <QDataStream>

class Book
{
public:
    Book();
    Book(const QString &name, const QString &author, const int &pages,
         const int &number, QDate &date);

    const QString &name() const;
    const QString &author() const;
    const int &pagesAmount() const;
    const int &cardNumber() const;
    const QDate &issueDate() const;

    void setData(const QString &name, const QString &author,
                 const int &pages, const int &number, QDate &date);
    void setBookName(const QString &name);
    void setBookAuthor(const QString &author);
    void setBookPagesAmount(const int &pages);
    void setBookCardNumber(const int &number);
    void setBookIssueDate(const QDate &date);

private:
    QString bookName;
    QString bookAuthor;
    int bookPagesAmount;
    int bookCardNumber;
    QDate bookIssueDate;
};

inline QDataStream &operator<< (QDataStream &ost, const Book &book){
    ost << book.name() << book.author()
        << book.pagesAmount() << book.cardNumber()
        << book.issueDate();
    return ost;
}

inline QDataStream &operator>> (QDataStream &ist, Book &book){
    QString name;
    QString author;
    int pagesAmount;
    int cardNumber;
    QDate issueDate;

    ist >> name >> author
        >> pagesAmount >> cardNumber
        >> issueDate;
    book.setData(name, author, pagesAmount, cardNumber, issueDate);

    return ist;
}

#endif // BOOK_H
