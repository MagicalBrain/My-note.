#include <iostream>
#include <memory>

class Widget : public std::enable_shared_from_this<Widget>
{
public:
    Widget(){
        std::cout << "Widget constructor run" << std::endl;
    }
    ~Widget(){
        std::cout << "Widget destructor run" << std::endl;
    }

    std::shared_ptr<Widget> GetSharedObject(){
        //return std::shared_ptr<Widget>(this);
        return shared_from_this();
    }
};

int main()
{
    std::shared_ptr<Widget> p(new Widget());
    std::shared_ptr<Widget> q = p->GetSharedObject();

    std::cout << p.use_count() << std::endl;
    std::cout << q.use_count() << std::endl;

    return 0;
}
