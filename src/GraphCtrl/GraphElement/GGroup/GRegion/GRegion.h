/***************************
@Author: Chunel
@Contact: chunel@foxmail.com
@File: GRegion.h
@Time: 2021/6/1 10:14 下午
@Desc: 实现多个element，根据依赖关系执行的功能
***************************/


#ifndef CGRAPH_GREGION_H
#define CGRAPH_GREGION_H

#include "../GGroup.h"
#include "../../GElementManager.h"

CGRAPH_NAMESPACE_BEGIN

/* region 中包含了 cluster 信息 */
class GRegion : public GGroup {
protected:
    explicit GRegion();
    ~GRegion() override;

    GRegion(const GRegion& region);
    GRegion& operator=(const GRegion& region);

    CStatus init() override;
    CStatus destroy() override;
    CStatus run() override;
    CStatus addElement(GElementPtr element) override;

private:
    GElementManagerPtr manager_;

    friend class GPipeline;
    friend class UAllocator;
};

using GRegionPtr = GRegion *;

CGRAPH_NAMESPACE_END

#endif //CGRAPH_GREGION_H
