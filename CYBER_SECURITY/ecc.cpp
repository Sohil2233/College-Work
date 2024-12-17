#include <iostream>
using namespace std;
const int p = 17;
const int a = 2;
const int b = 2;
struct Point
{
    int x;
    int y;
};
bool isOnCurve(Point point)
{
    int lhs = (point.y * point.y) % p;
    int rhs = (point.x * point.x * point.x + a * point.x + b) % p;
    return lhs == rhs;
}
Point addPoints(Point p1, Point p2)
{
    Point result;
    int slope;
    if (p1.x == p2.x && p1.y != p2.y)
    {
        result.x = 0;
        result.y = 0;
        return result;
    }

    if (p1.x == p2.x && p1.y == p2.y)
    {
        slope = (3 * p1.x * p1.x + a) % p;
        int inv = 0;
        while ((slope * inv) % p != 1)
        {
            inv++;
        }
        slope = ((3 * p1.x * p1.x + a) * inv) % p;
    }
    else
    {

        slope = ((p2.y - p1.y) % p + p) % p;
        int inv = 0;
        while ((p2.x - p1.x) * inv % p != 1)
        {
            inv++;
        }
        slope = ((p2.y - p1.y) * inv) % p;
    }
    result.x = ((slope * slope - p1.x - p2.x) % p + p) % p;
    result.y = ((slope * (p1.x - result.x) - p1.y) % p + p) % p;
    return result;
}
Point scalarMultiply(Point p, int k)
{
    Point result = p;
    for (int i = 1; i < k; ++i)
    {
        result = addPoints(result, p);
    }
    return result;
}
int main()
{
    // Example usage
    Point basePoint = {5, 1}; // Example base point

    // Sender's keys
    int senderPrivateKey = 7;                                            // Sender's private key
    Point senderPublicKey = scalarMultiply(basePoint, senderPrivateKey); // Sender's public key

    // Receiver's keys
    int receiverPrivateKey = 11;                                             // Receiver's private key
    Point receiverPublicKey = scalarMultiply(basePoint, receiverPrivateKey); // Receiver's public key

    cout << "Sender's public key: (" << senderPublicKey.x << ", " << senderPublicKey.y << ")" << endl;
    cout << "Sender's private key: " << senderPrivateKey << endl;
    cout << "Receiver's public key: (" << receiverPublicKey.x << ", " << receiverPublicKey.y << ")" << endl;
    cout << "Receiver's private key: " << receiverPrivateKey << endl;

    return 0;
}