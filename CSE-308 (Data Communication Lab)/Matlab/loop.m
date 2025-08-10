x = -pi:0.1:pi;

% Initialize y values
y = zeros(size(x));

% Calculate y values using a for loop
for i = 1:length(x)
    y(i) = sin(x(i));
end

% Plot the graph
plot(x, y);
title('Graph of y = sin(x)');
xlabel('x');
ylabel('y');
grid on; % Show grid