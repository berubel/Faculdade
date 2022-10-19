from django.urls import path
from rest_framework_simplejwt.views import (
    TokenObtainPairView,
    TokenRefreshView,
)
from . import views

urlpatterns = [
    path('', views.api_overview),
    path('token/', TokenObtainPairView.as_view(), name='token_obtain_pair'),
    path('refresh-token/', TokenRefreshView.as_view(), name='token_refresh'),
    path('transfer/<int:pk>/', views.TransferAPIView.as_view()),   
    path('receipt-list/<int:user_id>/', views.receipt_list),
    path('receipt-detail/<int:user_id>/<int:pk>/', views.receipt_detail)
]