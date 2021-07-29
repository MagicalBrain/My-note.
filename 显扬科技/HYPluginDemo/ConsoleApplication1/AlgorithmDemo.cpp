#include "AlgorithmDemo.h"

#include <iostream>

#include <algorithm/VoxelGridFilter.hpp>
#include <common/TimeHelper.h>
#include <common/LoggerHelper.hpp>

using namespace hy;

int AlgorithmDemo::param(const std::string& file)
{
	std::cout << file << std::endl;
	return 0;
}

int AlgorithmDemo::compute(int index, bool force, int max)
{
	std::cout << data_->Clouds.size() << std::endl;
	TimeHelper helper;
	
	VoxelGridFilter::Filter<pcl::PointXYZ>(data_->Clouds.front(), 5);
	/// xx
	/// xxx 
	/// PPF
	/// ....
	/// kkkk................
	/// 
	data_->Results.resize(max);
	HY_LOG_SEV(info) << boost::format("xxxx %1% ms") % helper.toc();
	return 0;
}
