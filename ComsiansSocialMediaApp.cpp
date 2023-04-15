#include <bits/stdc++.h>
#include <iostream>
#include <string>
#define SIZE 50
using namespace std;

class MyLinkedList{
public:
    string data;
    MyLinkedList *next = NULL;
    MyLinkedList *previous = NULL;
    MyLinkedList *first = NULL;
    MyLinkedList *last = NULL;

    void displayTheData(){
        MyLinkedList *p = first;
        if (first==NULL){
            cout<<"List Is Empty";
        }
        else {
            while(p!=NULL)
            {
                cout<<p->data<<endl;
            }
        }
    }
    void insert_end(string element){
        MyLinkedList *current = new MyLinkedList;
        current->data = element;
        if (first==NULL){
            first = last = current;
        }else{
            last->next = current;
            current->previous = last;
            last = current;
        }
    }
};

struct Post;

struct User
{
    string city;
    string username;
    string name;
    string password;
    queue<User*> requests;
    list<Post*> posts;
};
struct Post{
    int likes = 0;
    string myPost;
    list<User*> postUser;
};

struct Node
{
    User *user = NULL;
    int weight = 0;
};


Node *matrix[SIZE][SIZE];

void initialize();
void send_request(User *sender, User *receiver);
void mainMenu(User *user);
void signUp(User *user);
User* login();
User* search(string username);
void requests(User *user);
void showFriends(User *user);
void addPost(User *user);
void showMyPost(User *user);
void showFeed(User *user);
void likePost(User *user);
void dijkstra(string sourceNode);
void closeFriends(User *user);
void friendSuggestions(User *user);


void myMainCall(){
    cout << "************************************************************************************\n";
    cout << "                             COMSIANS SOCIAL MEDIA APP                               \n";
    cout << "************************************************************************************\n";
    cout << "\n";
    cout << "\n-----------------------------------------------------------------------------------\n";
    cout << "                          --WE ARE BEYOND THE EXCEPTIONS ---\n";
    cout << "                             -- WE HAVE FEATURES LIKE --\n";
    cout << "                  ***ACCOUNT CREATION*** \t ***FRIENDS SUGGESTION** \t ";
    cout << "\n-----------------------------------------------------------------------------------\n";
    cout << "\n\n";

    while (true) {
        cout << "Press \n1-LOGIN \n2-SIGN-UP \n0-EXIT\n";
        cout << "ENTER YOUR CHOICE: ";
        string opt;
        cin >> opt;

        if(opt == "1") {
            User *user = login();
            if(user!=NULL){
                mainMenu(user);
            } else{
                cout<<"\n<<<<<<<<<<<<<<<<<<< INCORRECT USERNAME OR PASSWORD >>>>>>>>>>>>>>>>>>>>\n";
            }
        } else if(opt == "2") {
//            User *user = new User;
//            cout<<"Enter Name: ";
//            cin>>user->name;
//
//            cout<<"Enter User name: ";
//            cin>>user->username;
//
//            cout<<"Enter Password: ";
//            cin>>user->password;
//            signUp(user);

//            string city;
//            cout<<"CHOOSE YOUR CITY NAME FROM THIS LIST";
//            cout<<"1) ISLAMABAD\n 2) KARACHI \n3) RAWALPINDI \n 4) HYDERABAD \n 5) QUETTA \n 6) LAHORE \n 7) PESHAWAR\n";
//            cout<<"ENTER YOUR CHOICE: ";
//            cin>>city;
//
//            if(city == "1"){
//                user->city = "ISLAMABAD";
//            }else if(city == "2"){
//                user->city = "KARACHI";
//            }else if(city == "3"){
//                user->city = "RAWALPINDI";
//            }else if(city == "4"){
//                user->city = "HYDERABAD";
//            }else if(city == "5"){
//                user->city = "QUETTA";
//            }else if(city == "6"){
//                user->city = "LAHORE";
//            }else if(city == "7"){
//                user->city = "PESHAWAR";
//            }else{
//                cout<<"<<<<<<<<<<<< WRONG INPUT >>>>>>>>>>> \n DEFAULT CITY ADDED IS ISLAMABAD\n";
//                user->city = "ISLAMABAD";
//            }
//
//            signUp(user);

            User *user = new User;
            user->city = "HYDERABAD";
            user->name = "Deepak";
            user->username = "deepak";
            user->password = "d";
            signUp(user);

            User *user2 = new User;
            user2->city = "RAWALPINDI";
            user2->name = "Rashid";
            user2->username = "rashid";
            user2->password = "r";
            signUp(user2);

            User *user3 = new User;
            user3->name = "Ahmad";
            user3->username = "ahmad";
            user3->password = "a";
            user3->city = "LAHORE";
            signUp(user3);

            User *user4 = new User;
            user4->city = "QUETTA";
            user4->name = "Faisal";
            user4->username = "faisal";
            user4->password = "f";
            signUp(user4);

            User *user5 = new User;
            user5->city = "PESHAWAR";
            user5->name = "Ibrar";
            user5->username = "ibrar";
            user5->password = "i";
            signUp(user5);

            User *user6 = new User;
            user6->city = "KARACHI";
            user6->name = "Ibrahim";
            user6->username = "ibrahim";
            user6->password = "i";
            signUp(user6);

            User *user7 = new User;
            user7->city = "LAHORE";
            user7->name = "Aaraiz";
            user7->username = "aaraiz";
            user7->password = "a";
            signUp(user7);

        }else if(opt == "0") {
            exit(0);
        } else {
            cout << "WRONG OPTION\n\n";
        }
    }
}
int main()
{
    initialize();
    myMainCall();
}

void mainMenu(User *user)
{
    string opt;
    cout << "-----------------------------------------------------\n";
    cout << "---------------- Welcome " + user->username + " ---------------------\n";
    cout << "-----------------------------------------------------\n";
    cout << "Press 1 SEND REQUESTS \nPress 2 CHECK FRIEND REQUESTS \nPress 3 SHOW MY FRIENDS \nPress 4 Add Post "
            "\nPress 5 Show my Posts \nPress 6 Show Feed\n Press 7 To show you Nearby Cities Distances "
            "\n Press 8 To Check your Closest Friend \n Press 9 To show Friend Suggestions \nPress 0 to exit" << endl;
    cout << "-----------------------------------------------\n";
    cout << "ENTER YOUR CHOICE: ";
    cin >> opt;

    if (opt == "1") {
        cout << "ENTER USER NAME TO SEND REQUEST: ";
        string recevierName;
        cin >> recevierName;
        User *recevier = search(recevierName);
        if (recevier != NULL) {
            send_request(user, recevier);
        } else{
            cout<<"RECIEVER NOT FOUND";
        }
        mainMenu(user);
    }else if(opt=="2"){
        string check;
        requests(user);
        while(true) {
            cout<<"Do you want to check request again?(y/n)";
            cin>>check;
            if(check == "y"){ requests(user);}
            else if(check == "n"){ break;}
            else{cout<<"WRONG OPTION";}
        }
        mainMenu(user);
    }else if(opt=="3"){
        showFriends(user);
        mainMenu(user);
    }else if(opt=="4"){
        addPost(user);
        mainMenu(user);
    }else if(opt=="5"){
        showMyPost(user);
        mainMenu(user);
    }else if(opt=="6"){
        showFeed(user);
        mainMenu(user);
    }else if(opt=="7"){
        dijkstra(user->city);
        mainMenu(user);
    }else if(opt=="8"){
        closeFriends(user);
        mainMenu(user);
    }else if(opt=="9"){
        friendSuggestions(user);
        mainMenu(user);
    }else if(opt=="0"){
        myMainCall();
    }else{
        cout << "Wrong Input\n";
        mainMenu(user);
    }
}

User* login() {
    string username;
    string password;
    cout << "Enter Your User Name: ";
    cin >> username;

    cout << "Enter Your Password: ";
    cin >> password;

    for (int i = 0; i < SIZE; ++i) {
        if(matrix[i][0]==NULL){
            return NULL;
        }else if (matrix[i][0]->user->username == username && matrix[i][0]->user->password == password) {
            return matrix[i][0]->user;
        }
    }
    return NULL;
}
void printStruct(const Post &post){
    cout<<"Post: "<<post.myPost<<" Likes: "<<post.likes<<endl;
};

void display(list<Post*> myList){
//    list<Post*>::iterator it;
//    for (it = myList.begin(); it != myList.end(); ++it){
//        cout<<*it<<endl;
//    }
    int count = 1;
    for(auto const &item: myList){
        cout<<count<<". ";
        printStruct(*item);
        count++;
    }
}

void initialize()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            matrix[i][j] = NULL;
        }
    }
}

int search(User *user)
{
    for (int i = 0; i < SIZE; i++)
    {
        if(matrix[i][0] == NULL)
        {
            return -1;
        }
        else if(matrix[i][0]->user->username == user->username)
        {
            return i;
        }
    }
    return -1;
}

void signUp(User *user)
{
    Node *node = new Node;
    node->user = user;
    for (int i = 0; i < SIZE; i++)
    {
        if (matrix[i][0] == NULL)
        {
            matrix[i][0] = node;
            return;
        }
    }
}

void send_request(User *sender, User *receiver)
{
    int sender_index = search(sender);
    int receiver_index = search(receiver);

    if (sender_index == -1 || receiver_index == -1)
    {
        cout << "User not found\n";
        return;
    }

    matrix[receiver_index][0]->user->requests.push(sender);
}

User* search(string username){
    for (int i = 0;i<SIZE;i++) {
        if(matrix[i][0]->user->username == username){
            return matrix[i][0]->user;
        }
    }
    return NULL;
}
void addFriend(User *user1,User *user2){
    int u1 = search(user1);
    int u2 = search(user2);

    Node *node1 = new Node;
    Node *node2 = new Node;

    node1->weight = 10;
    node2->weight = 10;

    node1->user = user1;
    node2->user = user2;

    for (int i = 0; i < SIZE; i++) {
        if(matrix[u1][i]== NULL ){
            matrix[u1][i] = node2;
            break;
        }
    }
    for (int i = 0; i < SIZE; i++) {
        if (matrix[u2][i] == NULL) {
            matrix[u2][i] = node1;
            break;
        }
    }
}
void requests(User *user){
    if(user->requests.empty()){
        cout<<"\nNO REQUESTS FOUND\n";
        return;
    }
    cout<<"NAME: "<<user->requests.front()->name<<endl;
    cout<<"USER NAME IS: "<<user->requests.front()->username<<endl;

    cout<<"\nTO ACCEPT ---> Press y \n TO REJECT ---> Press n\n";
    cout<<"ENTER YOUR CHOICE: ";
    string option;
    cin>>option;

    if(option=="y"){
        addFriend(user,user->requests.front());
        user->requests.pop();
    }else if(option=="n"){
        user->requests.pop();
    }else{
        cout<<"\nWRONG CHOICE\n";
        requests(user);
    }
}
void showFriends(User *user){
    int userIndex = search(user);
    for (int i = 1;i<SIZE;i++) {
        if(matrix[userIndex][i] == NULL){
            cout<<"\nEND OF FRIEND-LIST\n";
            return;
        }else{
            cout<<"MY FRIEND NAME: "<<matrix[userIndex][i]->user->name<<endl;
            cout<<"MY FRIEND USERNAME: "<<matrix[userIndex][i]->user->username<<endl;
        }
    }
}
void addPost(User *user){
    string post;
    cout<<"Add a posts: ";
    cin>>post;
    Post *newPost = new Post;
    newPost->myPost = post;
    user->posts.push_back(newPost);
    cout<<"\nPOST ADDED\n";
}
void showMyPost(User *user){
    display(user->posts);
}
bool postIdVerification(string id){
    for(int i=0;i<id.size();i++){
        if(!isdigit(id[i])){
            return false;
        }
    }
    return true;
}
void likePost(User *user) {
    string usernameInput;
    string id;

    cout << "Enter User Name: ";
    cin >> usernameInput;

    cout << "Enter Post Id: ";
    cin >> id;

    if (!postIdVerification(id)) {
        cout << "<<<<<<<<<<<<<<< INVALID POST ID >>>>>>>>>>>>>>" << endl;
        return;
    }
    int postId = stoi(id);
    int liked = search(search(usernameInput));
    if(liked == -1){
        cout<<"USER NOT FOUND";
        return;
    }
    Post *post = NULL;

    int count = 1;

    if (matrix[liked][0]->user->posts.size() < postId) {
        cout << "\n <<<<<<<<<<<<<<<< INVALID POST ID >>>>>>>>>>>>>> \n";
        return;
    }
    for (auto const &item: matrix[liked][0]->user->posts) {
        post = item;
        if (count >= postId) {
            break;
        }
        count++;
    }
    post->likes++;
    post->postUser.push_back(user);

    int liker = search(user);
    for (int i = 1; i < SIZE; i++) {
        if (matrix[liked][i] != NULL) {
            if (matrix[liked][i]->user->username == user->username) {
                matrix[liked][i]->weight -= 4;
            }
        }
        if (matrix[liked][i] != NULL) {
            if (matrix[liker][i]->user->username == matrix[liked][0]->user->username) {
                matrix[liker][i]->weight -= 4;
            }
        }
    }
}
void showFeed(User *user){
    int userIndex = search(user);
    for (int i = 1;i<SIZE;i++) {
        if(matrix[userIndex][i] == NULL){
            break;
        }else{
            cout<<"USER : "<<matrix[userIndex][i]->user->name<<" \nPOSTS:\n ";
            display(matrix[userIndex][i]->user->posts);
        }
    }
    likePost(user);
}
void dijkstra(string sourceNode){
    const int n = 7;
    string cities[n] = {"ISLAMABAD", "KARACHI", "RAWALPINDI", "HYDERABAD", "QUETTA", "LAHORE", "PESHAWAR"};

    const int i1 = 9999;
    int graph[n][n] = {
            {i1, 30, 5, i1, i1, i1, i1},
            {30, i1, i1, 6, 14, 12, i1},
            {5, i1, i1, i1, i1, 15, 10},
            {i1, 6, i1, i1, i1, i1, i1},
            {i1, 14, i1, i1, i1, i1, 20},
            {i1, 12, 15, i1, i1, i1, i1},
            {i1, i1, 10, i1, 20, i1, i1}
    };

    int src = -1;

    for(int i = 0; i<7; i++){
        if(sourceNode == cities[i]){
            src = i;
            break;
        }
    }
    if(src == -1){
        cout<<"Node does not exists"<<endl;
        return;
    }
    int count = 1;

    int path[n];
    for(int i=0;i<n;i++)
        path[i] = graph[src][i];

    int visited[n] = {0};
    visited[src] = 1;

    while(count<n)
    {
        int minNode;
        int minVal = i1;

        for(int i=0;i<n;i++)
            if(visited[i] == 0 && path[i]<minVal)
            {
                minVal = path[i];
                minNode = i;
            }

        visited[minNode] = 1;

        for(int i=0;i<n;i++)
            if(visited[i] == 0)
                path[i] = min(path[i],minVal+graph[minNode][i]);

        count++;
    }
    path[src] = 0;
    for(int i=0;i<n;i++)
        cout << "Shortest distance from " << sourceNode << " to " << cities[i] << " -> " << path[i] << endl;
}

void closeFriends(User *user){
    int userIndex = search(user);
    int minValue = INT16_MAX;

    User *user1 = NULL;
    for(int i=1;i<SIZE;i++){
        if(matrix[userIndex][i] == NULL){
            break;
        }else if(matrix[userIndex][i]->weight<minValue){
            user1 = matrix[userIndex][i]->user;
            minValue = matrix[userIndex][i]->weight;
        }
    }
    if(user1!=NULL){
        cout<<"^^^^^ YOUR CLOSEST FRIEND IS ^^^^^^^ "<<"\n\t"<<user1->name<<endl<<endl;
    }else{
        cout<<"YOU HAVE NO ANY CLOSE FRIEND"<<endl;
    }
}

bool myFriendExists(string userName,int index){
    for(int i=0;i<SIZE;i++) {
        if(matrix[index][i]== NULL){
            return false;
        }
        if(matrix[index][i]->user->username == userName){
            return true;
        }
    }
    return false;
}
void friendSuggestions(User *user){
    int userIndex = search(user);
    if(matrix[userIndex][1] == NULL){
        cout<<"NO FRIEND SUGGESTIONS LIST IS AVAILABLE\n";
        return;
    }
    for(int i=1;i<SIZE;i++) {
        if (matrix[userIndex][i] == NULL) {
            break;
        }else{
            int friendIndex = search(matrix[userIndex][i]->user);
            if(friendIndex == -1){
                cout<<"NO FRIEND SUGGESTIONS LIST IS AVAILABLE\n";
                return;
            }
            for(int j=1;j<SIZE;j++) {
                if(matrix[friendIndex][j] == NULL){
                    break;
                }else if(!myFriendExists(matrix[friendIndex][j]->user->username,userIndex)){
                    cout<<"SUGGESTED FRIEND IS: "<<matrix[friendIndex][j]->user->username<<endl;
                }
            }
        }
    }
}