add_executable(robot
  Main.cc
  Client.cc
  Robot.cc
  RobotCmd.cc
  RobotHandler.cc
  Opcodes.cc
  Sessions.cc
  Cmd.cc
  )
target_link_libraries(robot muduo_net_cpp11 muduo_base_cpp11)
