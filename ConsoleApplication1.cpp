 #include <iostream>

enum class Piece : char {
    PAWN = 'P',
    KNIGHT = 'N',
    BISHOP = 'B',
    ROOK = 'R',
    QUEEN = 'Q',
    KING = 'K',
    UNKNOWN = NULL
};

Piece getPieceBySymbol(char s) {
    switch (s)
    {
    case 'P': return Piece::PAWN;
    case 'N': return Piece::KNIGHT;
    case 'B': return Piece::BISHOP;
    case 'R': return Piece::ROOK;
    case 'Q': return Piece::QUEEN;
    case 'K': return Piece::KING;
    default: return Piece::UNKNOWN;
    }
}

const char* getPieceName(Piece p) {
    switch (p)
    {
    case Piece::PAWN:
        return "PAWN";
    case Piece::KNIGHT:
        return "KNIGHT";
    case Piece::BISHOP:
        return "BISHOP";
    case Piece::ROOK:
        return "ROOK";
    case Piece::QUEEN:
        return "QUEEN";
    case Piece::KING:
        return "KING";
    default:
        return "Unknown piece!";;
    }
}

using std::cout;
using std::endl;
using std::cin;

int main()
{
    char symbol;
    do
    {
        cout << "Enter the first symbol of a chess piece (capital):\n";
        cin >> symbol;
        cout << "\nThe chosen symbol represents the " << getPieceName(getPieceBySymbol(symbol));

    } while (symbol == '\0');
}