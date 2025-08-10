bits = [ 1 0 1 1 1 0 0];
count = 0;
result = zeros(1, length(bits));
for i = 1:length(t)
    if t(i) > count
    count = count + 1;
        if x(i) == 1
            result(count) = 1;
        else
            result(count) = 0;
        end
    end
end
disp('Decoding Data:');
disp(result);