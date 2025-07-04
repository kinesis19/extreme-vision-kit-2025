#ifndef extreme_vision_kit_2025_QNODE_HPP_
#define extreme_vision_kit_2025_QNODE_HPP_

#ifndef Q_MOC_RUN
#include <rclcpp/rclcpp.hpp>
#endif
#include <QThread>

class QNode : public QThread
{
    Q_OBJECT
public:
    QNode();
    ~QNode();

protected:
    void run();

private:
    std::shared_ptr<rclcpp::Node> node;

Q_SIGNALS:
    void rosShutDown();
};

#endif