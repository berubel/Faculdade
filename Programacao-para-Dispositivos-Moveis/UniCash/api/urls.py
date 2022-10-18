from django.urls import path
from . import views

urlpatterns = [
    path('', views.api_overview),
    path('transfer/<int:pk>/', views.TransferAPIView.as_view()),   
    path('receipt-list/<int:user_id>/', views.receipt_list),
    path('receipt-detail/<int:user_id>/<int:pk>/', views.receipt_detail)
]