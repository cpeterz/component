# import launch
# from launch_ros.actions import ComposableNodeContainer
# from launch_ros.descriptions import ComposableNode

# def generate_launch_description():
#     """Generate launch description with multiple components."""
#     container = ComposableNodeContainer(
#             name='my_container',
#             namespace='',
#             package='rclcpp_components',
#             executable='component_container',
#             composable_node_descriptions=[

#                  ComposableNode(
#                     package='composition_test',
#                     plugin='composition::Listener',
#                     name='listener')
               
#                  ComposableNode(
#                     package='composition_test',
#                     plugin='composition::Talker',
#                     name='talker'),
               
              
#             ],
#             output='screen',
#     )

#     return launch.LaunchDescription([container])
import launch
from launch_ros.actions import ComposableNodeContainer
from launch_ros.descriptions import ComposableNode

def generate_launch_description():
    container = ComposableNodeContainer(
            name='my_container',
            namespace='',
            package='rclcpp_components',
            executable='component_container',
            
            composable_node_descriptions=[
                ComposableNode(
                    package='composition_test',
                    plugin='composition::Listener',
                    name='listener'
                    ),
                ComposableNode(
                    package='composition_test',
                    plugin='composition::Talker',
                    name='talker'
                    )
            ],
            output='screen',
    )

    return launch.LaunchDescription([container])