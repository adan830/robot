file(GLOB_RECURSE sources_All *.cc)
									 
add_executable(robot
	${sources_All}
  )

target_link_libraries(robot muduo_net_cpp11 muduo_base_cpp11)
