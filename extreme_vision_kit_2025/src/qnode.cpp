#include "extreme_vision_kit_2025/qnode.hpp"

QNode::QNode()
{
    int argc = 0;
    char** argv = NULL;
    rclcpp::init(argc, argv);
    node = rclcpp::Node::make_shared("extreme_vision_kit_2025");
    this->start();
}

QNode::~QNode()
{
    if (rclcpp::ok())
    {
    rclcpp::shutdown();
}
}

void QNode::run()
{
    rclcpp::WallRate loop_rate(20);
    while (rclcpp::ok())
    {
    rclcpp::spin_some(node);
    loop_rate.sleep();
    }
    rclcpp::shutdown();
    Q_EMIT rosShutDown();
}