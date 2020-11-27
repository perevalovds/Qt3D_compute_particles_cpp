
/**
* @file     computeframegraph.h
*
* @brief     ComputeFramegraph class declaration.
*
*/

#ifndef COMPUTESHADER_COMPUTEFRAMEGRAPH_H
#define COMPUTESHADER_COMPUTEFRAMEGRAPH_H


#include <QPointer>
#include <Qt3DRender/QViewport>

namespace Qt3DRender {
    class QRenderSurfaceSelector;
    class QClearBuffers;
    class QNoDraw;
    class QDispatchCompute;
    class QTechniqueFilter;
    class QCameraSelector;
    class QCamera;
    class QFilterKey;
    class QMemoryBarrier;
}

namespace Qt3DCore {
    class QNode;
}

/**
* Framegraph for compzte shaders.
*/

class ComputeFramegraph : public Qt3DRender::QViewport
{

public:
    /**
    * Constructor of ComputeFramegraph class.
    */
    explicit ComputeFramegraph(Qt3DCore::QNode *parent = 0);
    
    /**
    *  Set the correct camera for the framegraph.
    */
    void setCamera(Qt3DRender::QCamera *pCamera);
    
private:
    /**
     * Init the ComputeMaterial class
     */
    void init();
    

    QPointer<Qt3DRender::QRenderSurfaceSelector> m_pSurfaceSelector;

    QPointer<Qt3DRender::QClearBuffers> m_pClearBuffers;

    //QPointer<Qt3DRender::QNoDraw> m_pNoDraw;

    QPointer<Qt3DRender::QDispatchCompute> m_pDispatchCompute;

    QPointer<Qt3DRender::QFilterKey> m_pComputeKey;
    QPointer<Qt3DRender::QFilterKey> m_pDrawKey;

    QPointer<Qt3DRender::QCameraSelector> m_pCameraSelector;

    QPointer<Qt3DRender::QTechniqueFilter> m_pComputeFilter;
    QPointer<Qt3DRender::QTechniqueFilter> m_pDrawFilter;

    QPointer<Qt3DRender::QMemoryBarrier> m_pMemoryBarrier;
};



#endif // COMPUTESHADER_COMPUTEFRAMEGRAPH_H
