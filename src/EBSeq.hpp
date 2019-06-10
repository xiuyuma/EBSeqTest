#pragma once

#include "aggregate.hpp"
#include <assert.h>
#include "partition.hpp"
#include "helper.hpp"

namespace EBS
{
    
    class EBSeq
    {
        
    public:
        virtual void gradientAscent(){};
         
        EBSeq(COUNTS& scRNAexpMatrix, std::vector<int>& cellCluster)
        {
            _clusinfo = helper::clusInfo(cellCluster);
            
            _sum = aggregate::sum(scRNAexpMatrix, _clusinfo);
            
            _mean = aggregate::groupMean(scRNAexpMatrix, _clusinfo);
        }
        
    protected:
        //on log scale
        virtual Float kernel()
        {
            return 0;
        }
        
        virtual COUNTS kernelDerivative()
        {
            return COUNTS();
        }
        
    protected:
        
        std::vector<Float> _hp;
        
        COUNTS _sum;
        
        CLUSINFO _clusinfo;
        
        COUNTS _mean;
    };

};
