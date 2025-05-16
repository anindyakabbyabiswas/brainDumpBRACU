#include <bits/stdc++.h>
void calcMoves(int M, int x, int y){
    int moves = 0;
    if ((1 <= (-1+x) && M >= (-1+x)) && (1 <= (-1+y) && M >= (-1+y))) moves++;
    if ((1 <= (-1+x) && M >= (-1+x)) && (1 <= (y) && M >= (y))) moves++;
    if ((1 <= (-1+x) && M >= (-1+x)) && (1 <= (1+y) && M >= (1+y))) moves++;
    if ((1 <= (x) && M >= (x)) && (1 <= (-1+y) && M >= (-1+y))) moves++;
    if ((1 <= (x) && M >= (x)) && (1 <= (1+y) && M >= (1+y))) moves++;
    if ((1 <= (1+x) && M >= (1+x)) && (1 <= (-1+y) && M >= (-1+y))) moves++;
    if ((1 <= (1+x) && M >= (1+x)) && (1 <= (y) && M >= (y))) moves++;
    if ((1 <= (1+x) && M >= (1+x)) && (1 <= (1+y) && M >= (1+y))) moves++;
    std::cout<<moves<<"\n";
}
void printMoves(int M, int x, int y){
    if ((1 <= (-1+x) && M >= (-1+x)) && (1 <= (-1+y) && M >= (-1+y))) std::cout<<-1+x<<" "<<-1+y<<"\n";
    if ((1 <= (-1+x) && M >= (-1+x)) && (1 <= (y) && M >= (y))) std::cout<<-1+x<<" "<<y<<"\n";
    if ((1 <= (-1+x) && M >= (-1+x)) && (1 <= (1+y) && M >= (1+y))) std::cout<<-1+x<<" "<<1+y<<"\n";
    if ((1 <= (x) && M >= (x)) && (1 <= (-1+y) && M >= (-1+y))) std::cout<<x<<" "<<-1+y<<"\n";
    if ((1 <= (x) && M >= (x)) && (1 <= (1+y) && M >= (1+y))) std::cout<<x<<" "<<1+y<<"\n";
    if ((1 <= (1+x) && M >= (1+x)) && (1 <= (-1+y) && M >= (-1+y))) std::cout<<1+x<<" "<<-1+y<<"\n";
    if ((1 <= (1+x) && M >= (1+x)) && (1 <= (y) && M >= (y))) std::cout<<1+x<<" "<<y<<"\n";
    if ((1 <= (1+x) && M >= (1+x)) && (1 <= (1+y) && M >= (1+y))) std::cout<<1+x<<" "<<1+y<<"\n"; 
}
int main(){
    // Fast IO
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int M;
    int x,y;
    std::cin>>M;
    std::cin>>x>>y;
    calcMoves(M, x, y);
    printMoves(M, x, y);
}