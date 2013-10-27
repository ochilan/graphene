/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * the COPYING file for more details */


#ifndef SINGLEPOINTCLOUDVIS_H_
#define SINGLEPOINTCLOUDVIS_H_


#include <pcl/keypoints/uniform_sampling.h>

#include <Color/Colors.h>
using namespace Color::Colors;

#include <Geometry/PCLTools.h>
using Geometry::PCLTools;
typedef pcl::PointNormal Point;
typedef PCLTools<Point>  Tools;
typedef Tools::CloudType Cloud;
typedef Tools::Idx       Idx;
typedef Tools::IdxSet    IdxSet;

#include <FW/FWVisualizer.h>
#include <Library/Rendered/Cloud.h>

namespace FW {


class SinglePointCloud : virtual public Visualizer {
	public:
		SinglePointCloud(std::string id, const GUI::Property::Paths& paths);
		virtual ~SinglePointCloud();

		void init();
		void render();
		void addProperties();
		void registerEvents();

	protected:
		void addClouds(const GUI::Property::Paths& paths);
		void exportCloud(const fs::path& path);
		void uploadCloud();
		void resample();
	
	protected:
		GUI::Property::Paths     m_paths;
		Cloud::Ptr               m_cloud;
		Rendered::Cloud::Ptr     m_rendered;
};

#include "SinglePointCloud.inl"

} // FW

#endif /* SINGLEPOINTCLOUDVIS_H_ */
