from algorithm import ssifl2
from metamodel import SupportVectorRegression
from mmgpy.surrogate.test import TestFunctionSet2DInputSpace

F2D = TestFunctionSet2DInputSpace()

from sklearn.preprocessing import MinMaxScaler

scalert1_2 = MinMaxScaler(feature_range=(0, 1))

model_t1_2 = ssifl2(epsilon=0.15,
                    delta=0.2,
                    function=F2D[0],
                    n=2,
                    hpopt=True,
                    model_handle_cls=SupportVectorRegression,
                    scaler=scalert1_2,
                    path="./test2.sv")
                    #                   train_on="new",
                    # cumulative_learning_importance=False)
